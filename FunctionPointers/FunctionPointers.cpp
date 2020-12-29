#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void print_message(int value)
{
    std::cout << "Hello " << value << std::endl;
}

bool match(std::string test)
{
    return test.size() == 5;
}

int count_strings_of_five(std::vector<std::string>& texts, bool (*matching_string)(std::string test))
{
    int counter = 0;
    for (int i = 0; i < texts.size(); i++)
    {
        if (match(texts[i]))
        {
            counter++;
        }
    }
    return counter;
}


int main()
{
    print_message(7);

    void (*p_print_message)(int) = print_message;
    p_print_message = print_message;

    p_print_message(8);


    ///////////////////////////////////////////////////////////////////////


    std::vector<std::string> texts;
    texts.push_back("aaaaa");
    texts.push_back("aaaaa");
    texts.push_back("aaa");
    texts.push_back("aaaaa");
    texts.push_back("aaaaaaa");

    std::cout << std::count_if(texts.begin(), texts.end(), match) << std::endl;

    std::cout << count_strings_of_five(texts, match);
}

