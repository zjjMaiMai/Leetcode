/*
给定一个固定的矩阵 M, 需要频繁获取其任意子矩阵的和。
*/

#include <iostream>
#include <vector>
#include <assert.h>

using Matrix = std::vector<std::vector<int>>;

class Solution {
public:
    void set_matrix(Matrix m)
    {
        int row = int(m.size());
        int col = int(m[0].size());
        _integral = std::vector<std::vector<int>>(row, std::vector<int>(col, 0));

        for (int r = 0; r < row; r++)
        {
            int sum_this_row = 0.0;
            for (int c = 0; c < col; c++)
            {
                sum_this_row += m[r][c];
                if (r > 0)
                {
                    _integral[r][c] = _integral[r - 1][c] + sum_this_row;
                }
                else
                {
                    _integral[r][c] = sum_this_row;
                }
            }
        }
    }

    int get_sum_of_sub_matrix(int row, int row_end, int col, int col_end)
    {
        int sum_large = 0;
        int sum_small = 0;
        int sum_left = 0;
        int sum_top = 0;

        sum_large = _integral[row_end - 1][col_end - 1];

        if (row > 0 && col > 0)
        {
            sum_small = _integral[row - 1][col - 1];
        }

        if (row_end > 0 && col > 0)
        {
            sum_left = _integral[row_end - 1][col - 1];
        }

        if (col_end > 0 && row > 0)
        {
            sum_top = _integral[row - 1][col_end - 1];
        }

        return sum_large + sum_small - sum_left - sum_top;
    }

private:
    Matrix _integral;
};


int main(int argc, char* argv[])
{
    Solution solution;
    solution.set_matrix({
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16} });
    assert(solution.get_sum_of_sub_matrix(0, 1, 0, 1) == 1);
    assert(solution.get_sum_of_sub_matrix(0, 1, 0, 4) == (1 + 2 + 3 + 4));
    assert(solution.get_sum_of_sub_matrix(0, 4, 0, 1) == (1 + 5 + 9 + 13));
    assert(solution.get_sum_of_sub_matrix(1, 4, 0, 1) == (5 + 9 + 13));
    assert(solution.get_sum_of_sub_matrix(1, 3, 2, 4) == (7 + 8 + 11 + 12));
    assert(solution.get_sum_of_sub_matrix(0, 4, 0, 4) == (17 * 8));
    return 0;
}