/*
题目描述
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

#include <vector>
#include <assert.h>

class Solution {
public:
    bool Find(int target, std::vector<std::vector<int>> array)
    {
        if (array.empty())
        {
            return false;
        }

        if (array[0].empty())
        {
            return false;
        }

        size_t max_rows = array.size();
        size_t max_cols = array[0].size();
        size_t row_invert = 0;
        size_t col = 0;

        while (row_invert < max_rows && col < max_cols)
        {
            auto value = array[max_rows - row_invert - 1][col];
            if (value == target)
            {
                return true;
            }
            else if (value > target)
            {
                row_invert++;
            }
            else
            {
                col++;
            }
        }
        return false;
    }
};


int main(int argc, char* argv[])
{
    Solution solution;
    assert(solution.Find(
        5,
        { {1, 2, 8, 9},
        {2, 4, 9, 12},
        {4, 7, 10, 13},
        {6, 8, 11, 15} }) == false);
    return 0;
}