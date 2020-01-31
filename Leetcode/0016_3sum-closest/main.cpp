/*
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum-closest
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        if(nums.size() <= 3)
        {
            return std::accumulate(nums.begin(), nums.end(), 0);
        }

        std::sort(nums.begin(), nums.end());

        int res = std::numeric_limits<int>::max();
        for(auto i = nums.begin(); i < nums.end() - 2 && res != 0; ++i)
        {
            auto j = i + 1;
            auto k = nums.end() - 1;

            while(j < k)
            {
                int res_this = *i + *j + *k - target;
                if(std::abs(res_this) < std::abs(res))
                {
                    res = res_this;
                    if(res == 0)
                    {
                        return target;
                    }
                }

                if(res_this < 0)
                {
                    ++j;
                }
                else
                {
                    --k;
                }
            }
        }
        return res + target;
    }
};