/*
给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

示例 1 :

输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
说明 :

数组的长度为 [1, 20,000]。
数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subarray-sum-equals-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include <assert.h>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        int sum = 0, ret = 0;
        std::unordered_multiset<int> hash_table{ 0 };

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];

            ret += hash_table.count(sum - k);
            hash_table.insert(sum);
        }
        return ret;
    }
};


int main(int argc, char* argv[])
{
    Solution solution;
    assert(solution.subarraySum(vector<int>{ 1, 1, 1 }, 2) == 2);
    return 0;
}