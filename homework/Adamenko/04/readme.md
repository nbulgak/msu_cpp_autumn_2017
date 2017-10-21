### Практическая часть

Нужно написать класс-матрицу, тип элементов double. 
    - В конструкторе задается количество рядов и строк.          Ok
    - Поддерживаются оперции: получить количество строк/столбцов Ok
    - получить конкретный элементов                              Ok
    - умножить на вектор                                         Ok
      (в качестве вектора использовать класс 
        ```std::vector<double>```),
    умножить на число                                            Ok
    - сравнение на равенство/неравенство                         Ok
    - В случае ошибки выхода за границы достаточно такой         Ok
        обработки ошибки: ```assert(!"index out of range")```

Пример:

```c++
const size_t rows = 5;
const size_t cols = 3;

Matrix m(cols, rows);

m[1][2] = 5; // колонка 1, строка 2
double x = m[3][1];

m *= 3; // умножение на число

std::vector<double> v = { 1, 2, 3 };
m *= v; // умножение на вектор

Matrix m1(cols, rows);

if (m1 == m)
{
}
```

Код должен быть покрыт тестами. Пример теста:

```c++
void check(bool value)
{
    if (!value)
        std::cout << "error" << std::endl;
}

void checkGetSet()
{
    Matrix m(2, 3);
    m[0][0] = 1;
    m[0][1] = 2;
    m[0][2] = 3;
    m[1][0] = 4;
    m[1][1] = 5;
    m[1][2] = 6;
    
    check(m[0][0] == 1);
    check(m[0][1] == 2);
    check(m[0][2] == 3);
    check(m[1][0] == 4);
    check(m[1][1] == 5);
    check(m[1][2] == 6);
    
    m[1][2] = 100;
    
    check(m[1][2] == 100);
}
```

##### Подсказка

Чтобы реализовать семантику [][] понадобится прокси-класс. Оператор матрицы возращает другой класс, в котором тоже используется оператор [] и уже этот класс возвращает значение.