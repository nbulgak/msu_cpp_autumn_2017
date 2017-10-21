## Класс-матрица

### Описание
    В конструкторе задается количество рядов и строк. Поддерживаются операции: получить количество строк/столбцов, получить конкретный элемент, умножить на вектор (в качестве вектора - класс std::vector<double>), умножить на число, сравнение на равенство/неравенство. Осуществляется проверка выхода за границы матрицы.
    Осуществляется проверка корректности операций на заданном наборе значений. Результат работы программы - количество и вид ошибок.

### Компиляция программы 
    Осуществляется либо при помощи make, либо g++ main.cpp -o matrix --std=c++11 -Wall

### Запуск программы: 
    ./matrix