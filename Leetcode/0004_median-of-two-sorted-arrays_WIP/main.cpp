/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        if (nums1.empty())
        {
            int size = nums2.size();
            if (size % 2 == 0)
            {
                return double(nums2[size / 2 - 1] + nums2[size / 2]) / 2;
            }
            else
            {
                return double(nums2[size / 2]);
            }
        }
        else if (nums2.empty())
        {
            int size = nums1.size();
            if (size % 2 == 0)
            {
                return double(nums1[size / 2 - 1] + nums1[size / 2]) / 2;
            }
            else
            {
                return double(nums1[size / 2]);
            }
        }
    }
};