Программа реализует простой калькулятор.
Вычисляет значение выражения, переданного в виде аргумента командной строки. 
В процессе вычисляется вещественное значение, на экран выводится оно, приведенное к целому.
В выражении разрешены константы Pi (3.14) и e (2.7).
При появлении ошибки программа сообщает об этом.

Сборка: команда make.

Использование: calc "выражение"

Семантика выражения (разрешены скобки):
 expr = term | expr + term | expr - term 
 term = prim | term * prim | term / prim
 prim = - number | number
 number = [0,9]+