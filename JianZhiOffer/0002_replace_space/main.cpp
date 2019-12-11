/*
题目描述
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/

#include <iostream>
#include <vector>
#include <assert.h>

class Solution {
public:
    void replaceSpace(char *str, int length)
    {
        if (length < 1)
        {
            return;
        }

        std::vector<int> table;
        for (int i = 0; i < length; i++)
        {
            if (str[i] == ' ')
            {
                table.push_back(i);
            }
        }

        if (table.empty())
        {
            return;
        }

        int need_move_back = int(table.size() * 2);
        int last_index = length;
        for (int i = int(table.size()) - 1; i >= 0; i--)
        {
            std::move(str + table[i], str + last_index, str + table[i] + (i + 1) * 2);
            std::memcpy(str + table[i] + i * 2, "%20", 3);
            last_index = table[i];
        }
    }
};


int main(int argc, char* argv[])
{
    std::vector<char> src(128, 0);
    std::strcpy(src.data(), "We Are Happy.");

    Solution solution;
    solution.replaceSpace(src.data(), sizeof("We Are Happy."));

    auto it = src.begin();
    while (it != src.end() && *it != 0)
    {
        std::cout << *it++;
    }
    return 0;
}