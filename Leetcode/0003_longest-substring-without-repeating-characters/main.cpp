/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <assert.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() <= 1)
        {
            return int(s.size());
        }

        std::vector<int> hash_table(256, -1);

        int start = 0;
        int max_len = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int& ref = hash_table[s[i]];
            if (ref >= start)
            {
                start = ref + 1;
            }
            ref = i;
            max_len = std::max(max_len, i - start + 1);
        }
        return max_len;
    }
};

int main(int argv, char* argc[])
{
    Solution solution;
    assert(solution.lengthOfLongestSubstring("abcabcbb") == 3);
    assert(solution.lengthOfLongestSubstring("bbbbb") == 1);
    assert(solution.lengthOfLongestSubstring("pwwkew") == 3);
    assert(solution.lengthOfLongestSubstring("abba") == 2);
    return 0;
}