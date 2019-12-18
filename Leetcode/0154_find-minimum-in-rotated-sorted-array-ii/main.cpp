/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

请找出其中最小的元素。

注意数组中可能存在重复的元素。

示例 1：

输入: [1,3,5]
输出: 1
示例 2：

输入: [2,2,2,0,1]
输出: 0
说明：

这道题是 寻找旋转排序数组中的最小值 的延伸题目。
允许重复会影响算法的时间复杂度吗？会如何影响，为什么？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums)
    {
        return findMin(nums.begin(), nums.end() - 1);
    }
private:
    typedef vector<int>::iterator iter;
    int findMin(iter front, iter back)
    {
        if (std::distance(front, back) == 0)
        {
            return *front;
        }

        if (*back > *front)
        {
            return *front;
        }

        while (front < back)
        {
            iter mid = front + std::distance(front, back) / 2;

            if (*mid > *back)
            {
                front = mid + 1;
            }
            else if (*mid < *back)
            {
                back = mid;
            }
            else
            {
                return std::min(findMin(front, mid), findMin(mid + 1, back));
            }
        }
        return *front;
    }
};


int main(int argv, char* argc[])
{
    Solution solution;
    assert(solution.findMin(std::vector<int>{3, 4, 5, 1, 2}) == 1);
    assert(solution.findMin(std::vector<int>{4, 5, 6, 7, 0, 1, 2}) == 0);
    assert(solution.findMin(std::vector<int>{1, 3, 5}) == 1);
    assert(solution.findMin(std::vector<int>{2, 2, 2, 0, 1}) == 0);
    return 0;
}