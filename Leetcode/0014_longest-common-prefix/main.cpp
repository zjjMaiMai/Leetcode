/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-common-prefix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        if(strs.empty())
        {
            return "";
        }

        int lenght = std::numeric_limits<int>::max();
        for(auto& s : strs)
        {
            lenght = std::min(lenght, int(s.size()));
        }

        int common_lenght = 0;
        for(int i = 0; i < lenght; i++)
        {
            char c = strs[0][i];
            for(int j = 1; j < strs.size(); j++)
            {
                if(strs[j][i] != c)
                {
                    return strs[0].substr(0, common_lenght);
                }
            }
            common_lenght++;
        }
        return strs[0].substr(0, common_lenght);
    }
};