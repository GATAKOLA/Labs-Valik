#include <iostream>

/*
int hello(int x);

int main() 
{
    int result = hello(5);
    std::cout << "Result: " << result << std::endl;
    return 0;
}

Если скомпилировать это то даст ошибку: undefined reference to `hello(int)'
Это означает что компилятор не знает что это за функция, поскольку нет её определения.
*/

int hello(int x)
{
    return x * 2;
}

int main()
{
    int result = hello(5);
    std::cout << "Result: " << result << std::endl;
    return 0;
}