/*
Write a function that normally takes one argument, the address of a string, and
prints that string once. However, if a second, type int, argument is provided and is
nonzero, the function should print the string a number of times equal to the number
of times that function has been called at that point. (Note that the number of
times the string is printed is not equal to the value of the second argument; it is
equal to the number of times the function has been called.) Yes, this is a silly function,
but it makes you use some of the techniques discussed in this chapter. Use the
function in a simple program that demonstrates how the function works.
*/

/*
Write a template function max5() that takes as its argument an array of five items
of type T and returns the largest item in the array. (Because the size is fixed, it can
be hard-coded into the loop instead of being passed as an argument.) Test it in a
program that uses the function with an array of five int value and an array of five
double values.
*/

#include <iostream>

void static_print(std::string* pStr, int x = 0);

template <typename T>
T max5(const T* one);

int main()
{
    std::string *s = new std::string("Hello World!");
    static_print(s);
    static_print(s);
    static_print(s);
    static_print(s,3);
    delete s;

    int x[]{ 1,2,6,4,5 };
    double y[] = { 1.1,2.0,3.0,5.5,6.21 };

    std::cout << max5(x) << std::endl;
    std::cout << max5(y) << std::endl;
}

void static_print(std::string* pStr, int x)
{
    static int counter = 0;
    counter++;
    if (x == 0)
    {
        std::cout << (*pStr)[0] << std::endl;
    }
    else
    {
        for (int i = 0; i < counter; i++)
        {
            std::cout << *pStr << std::endl;
        }
    }
}

template <typename T>
T max5(const T* one)
{
    T result = one[0];
    for (int i = 0; i < 5; i++)
    {
        if (one[i] > result)
        {
            result = one[i];
        }
    }
    return result;
}