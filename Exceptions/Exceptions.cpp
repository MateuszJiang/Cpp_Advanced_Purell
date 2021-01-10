
#include <iostream>

int count_chars(char* x, char y)
{
    if (x == nullptr)
    {
        return 1;
    }
    int counter = 0;
    {
        while (*x)
        {
            std::cout << *x << std::endl;
            if (*x == y)
            {
                counter++;
            }
            x++;
        }
    }
    return counter;
}


int main()
{
    char y = 'x';
    char* x = new char[7];

    *(x + 6) = '\0';

    for (char* it = x; *it; it++)
    {
        *it = 'x';
    }

    std::cout << count_chars(x, y);

    delete[] x;
}

