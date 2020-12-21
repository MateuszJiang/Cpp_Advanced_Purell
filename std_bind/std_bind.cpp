// bind.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>

class Test
{
public:
    int add(int a, int b, int c)
    {
        std::cout << a << ", " << b << ", "
            << c << std::endl;
        return a + b + c;
    }
};

int run(std::function<int(int, int)> func)
{
    return func(7, 3);
}

int main()
{
    Test test;

    auto calculate = std::bind(&Test::add, test, 1, std::placeholders::_2, std::placeholders::_1);

    std::cout << run(calculate);

    return 0;
}