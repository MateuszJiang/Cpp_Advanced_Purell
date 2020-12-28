#include <iostream>

void test(int value)
{
    std::cout << "Hello " << value << std::endl;
}

int main()
{
    test(7);

    void (*pTest)(int) = test;
    pTest = test; 

    pTest(8);
}

