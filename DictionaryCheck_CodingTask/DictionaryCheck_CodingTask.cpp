//=================================================================

// Given a dictionary of valid words (dictionary), and an input string (input) 
// containing two wildcard characters ('?'), implement the function 'checkwords'
// to fill in the list of valid words in 'dictionary' that can be made from the 
// letters in 'input'.
//
// Example, When the WordsWithProgrammers() function is called it will produce
// the following output if checkWords() is implemented correctly
// given the input "t?ac?" the output should be:
// 
// 7 valid words found ...
// at
// act
// tat
// cat
// take
// acted
// trace

//=================================================================


#include <iostream>
#include <string>
#include <vector>

bool isValidWord(std::string cleanInput, int jokers, std::string dict_word);

void checkWords(const std::string& input, const std::vector<std::string>& dictionary, std::vector<std::string>& validWords)
{
    size_t inputLength = input.length();

    std::string cleanInput;
    int jokers = 0; // # of "?" in string

    for (char letter : input)
    {
        if (letter == '?')
            jokers++;
        else
            cleanInput.push_back(letter);
    }
    for (std::string dict_word : dictionary)
    {
        if (dict_word.length() <= inputLength)
        {
            if (isValidWord(cleanInput, jokers, dict_word))
            {
                validWords.push_back(dict_word);
            }
        }
    }
}
bool isValidWord(std::string cleanInput, int jokers, std::string dict_word)
{
    for (char letter : dict_word)
    {
        size_t found_char_position = cleanInput.find(letter);
        if (found_char_position == std::string::npos) // if letter not found in the string
            jokers--;
        else
            cleanInput.erase(found_char_position, 1);
    }
    if (jokers >= 0)
        return true;
    else
        return false;
}

int main()
{
    std::vector<std::string> dictionary;
    dictionary.push_back(std::string("at"));
    dictionary.push_back(std::string("act"));
    dictionary.push_back(std::string("tat"));
    dictionary.push_back(std::string("dog"));
    dictionary.push_back(std::string("cat"));
    dictionary.push_back(std::string("take"));
    dictionary.push_back(std::string("acted"));
    dictionary.push_back(std::string("plane"));
    dictionary.push_back(std::string("mouse"));
    dictionary.push_back(std::string("trace"));
    dictionary.push_back(std::string("truce"));
    dictionary.push_back(std::string("traced"));
    dictionary.push_back(std::string("acting"));
    dictionary.push_back(std::string("trance"));
    dictionary.push_back(std::string("placating"));
    dictionary.push_back(std::string("aaaaa"));

    std::vector<std::string> validWords;

    std::string input("t?ac?");

    checkWords(input, dictionary, validWords);

    if (validWords.size() == 0)
    {
        std::cout << "no valid words found :-(\n";
    }
    else
    {
        std::cout << validWords.size() << " valid words found ...\n";

        for (std::string& s : validWords)
        {
            std::cout << s << std::endl;
        }
    }
}
