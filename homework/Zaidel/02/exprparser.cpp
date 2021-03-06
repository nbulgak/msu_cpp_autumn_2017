#include <iostream>


enum class Token
{
    Invalid = 0,
    Minus = 1,
    Plus = 2,
    Mul = 3,
    Div = 4,
    Number = 5,
    End = 6
};


// получение текущего токена
Token getToken(const char*& text, bool isShiftedAfterOperation = true, bool isShiftedAfterNumber = false)
{
    const  char* prev_text = text;

    while (const auto c = *text++)
    {
        switch (c) {
            case ' ':
                continue;
            case '-':
                if(!isShiftedAfterOperation)
                    text = prev_text;
                return Token::Minus;
            case '+':
                if(!isShiftedAfterOperation)
                    text = prev_text;
                return Token::Plus;
            case '/':
                if(!isShiftedAfterOperation)
                    text = prev_text;
                return Token::Div;
            case '*':
                if(!isShiftedAfterOperation)
                    text = prev_text;
                return Token::Mul;
        }

        if (c >= '0' && c <= '9') {
            for (auto c = *(text); c>= '0' && c<= '9';)
            {
                //skip digits
                ++text;
                c =  *text;
            }

            if(!isShiftedAfterNumber)
                text = prev_text;

            return Token::Number;
        }
        return Token::Invalid;
    }
    return Token ::End;
}

bool isNegativeNumber(const char*& text)
{
    const char* prev_text = text;

    if(getToken(text) == Token::Minus)
    {
        return true;
    }


    text = prev_text;
    return  false;
}

// вычисление числа с унарным минусом
int prim(const char*& text)
{

    bool isNegative = isNegativeNumber(text);

    int res  = 0;
    bool isNumber = false;

    for(;(*text >= '0' && *text <= '9') || *text == ' ' ; ++text)
    {
        if(*text == ' ')
            continue;

        res = res * 10 + (*text - '0');
        isNumber = true;
    }

    if(!isNumber)
        throw std::runtime_error("Error in number input!");

    if(isNegative)
        return -res;
    else
        return res;
}


//  вычисление терма в выражении
int term(const char*& text)
{
    int res = prim(text);

    Token tk = getToken(text);
    while (tk  == Token::Mul || tk == Token::Div)
    {
        if(tk == Token::Mul)
        {
           int pr = prim(text);
           res *=  pr;
        }

        if(tk == Token::Div)
        {
            int pr = prim(text);
            if(pr == 0)
            {
                throw std::runtime_error("Division by zero!");
            }

            res /=  pr;
        }

        tk = getToken(text);
    }
    --text;

    return  res;
}

// сложение и вычитание термов
int expr(const char*& text)
{
    int res = term(text);

    Token tk;

    tk = getToken(text);
    for (;tk != Token::End; tk = getToken(text))
    {

          if(tk == Token::Invalid)
          {
              throw std::runtime_error("Invalid character!");
          }

          if(tk == Token::Plus)
          {
              res += term(text);
          }
          if(tk == Token::Minus)
          {
              res -= term(text);
          }
    }

    return  res;
}


int main(int argc, char* argv[])
{
    const char* text = "";


    if (argc == 1)
    {
        std::cout << "Empty input!"  << std::endl;
        return -1;
    }
    text = argv[1];

    if(getToken(text, false, false) == Token::End)
    {
        std::cout<<"Empty input!"<< std::endl;
        return -1;
    }


    try
    {
        int res = expr(text);
        std::cout<<res<<std::endl;
    }
    catch (std::exception& ex)
    {
       std::cout<<ex.what()<<std::endl;
       return -1;
    }

    return 0;
}
