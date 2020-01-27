/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        auto check = [&](int& begin, int& end)
        {
            while(true)
            {
                int begin_new = begin - 1;
                int end_new = end + 1;

                if(begin_new < 0 || end_new >= s.size())
                {
                    break;
                }
                if(s[begin_new] != s[end_new])
                {
                    break;
                }
                begin = begin_new;
                end = end_new;
            }
        };

        if(s.size() <= 1)
        {
            return s;
        }
        
        int start = 0;
        int max_lenght = 1;

        for(int i = 0; i < s.size() - 1; i++)
        {
            {
                int begin = i;
                int end = i;
                check(begin, end);
                if(end - begin + 1 > max_lenght)
                {
                    start = begin;
                    max_lenght = end - begin + 1;
                }
            }

            if(s[i] == s[i+1])
            {
                int begin = i;
                int end = i + 1;
                check(begin, end);
                if(end - begin + 1 > max_lenght)
                {
                    start = begin;
                    max_lenght = end - begin + 1;
                }
            }
        }
        return s.substr(start, max_lenght);
    }
};

int main(int argv, char *argc[])
{
    Solution solution;
    assert(solution.longestPalindrome("babad") == "bab");
    assert(solution.longestPalindrome("cbbd") == "bb");
}