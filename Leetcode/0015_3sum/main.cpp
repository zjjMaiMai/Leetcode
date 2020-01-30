/*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> ret;

        if(nums.size() < 3)
        {
            return ret;
        }

        if(nums.size() == 3)
        {
            if(nums[0] + nums[1] + nums[2] == 0)
            {
                ret.emplace_back(std::move(nums));
            }
            return ret;
        }

        std::sort(nums.begin(), nums.end());

        for(auto i = nums.begin(); i != nums.end() - 2; ++i)
        {
            if(*i > 0)
            {
                break;
            }

            if(i != nums.begin() && *i == *(i - 1))
            {
                continue;
            }

            auto j = i + 1;
            auto k = nums.end() - 1;
            bool reset = false;

            while(j < k)
            {
                if(reset)
                {
                    if(*j == ret.back()[1])
                    {
                        ++j;
                        continue;
                    }

                    if(*k == ret.back()[2])
                    {
                        --k;
                        continue;
                    }
                }
                
                int sum = *i + *j + *k;
                if(sum > 0)
                {
                    --k;
                }
                else if(sum < 0)
                {
                    ++j;
                }
                else
                {
                    ret.push_back(std::vector<int>{*i, *j, *k});
                    reset = true;
                    ++j;
                    --k;
                }
            }
        }

        return ret;
    }
};