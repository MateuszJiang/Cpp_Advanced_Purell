#include <stdexcept>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

struct myclass {
    bool operator() (int i, int j) { return (i < j); }
} myobject;
std::pair<int, int> checkList(const std::vector<int>& list, int sum)
{
    for (int i = 0; i < list.size() - 1; i++)
    {
        for (int j = i + 1; j < list.size(); j++)
        {
            if (list[i] + list[j] == sum )
                return std::make_pair<int>((int)list[i], (int)list[j]);
        }
    }
}
int getIndex(std::vector<int> v, int K)
{
    auto it = find(v.begin(), v.end(), K);
    if (it != v.end())
    {
        int index = it - v.begin();
        return index;
    }
    else
        return -1;
}

std::pair<int, int> findTwoSum(const std::vector<int>& list, int sum)
{
    std::vector<int> my_list = list;
    std::sort(my_list.begin(), my_list.end(), myobject);

    int x = 0;
    for (x; x < my_list.size(); x++)
        if (my_list[x] >= sum)
            break;

    auto my_list_v2 = std::vector<int>(my_list.begin(), my_list.begin() + x);
    if (my_list_v2.size() < 2)
        return std::make_pair<int>(-1, -1);

    std::pair<int, int> mypair = checkList(my_list_v2, 10);


    return std::make_pair<int>(getIndex(list, mypair.first), getIndex(list, mypair.second));
}


#ifndef RunTests
int main()
{
    std::vector<int> list = { 3, 1, 5, 7, 5, 9 };
    std::pair<int, int> indices = findTwoSum(list, 10);
    std::cout << indices.first << '\n' << indices.second;
}
#endif