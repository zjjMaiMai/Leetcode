/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。



示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    vector<string> letterCombinations(string digits) 
    {
        std::vector<std::string> ret;
        if(digits.empty())
        {
            return ret; 
        }

        const std::vector<std::string> map = {
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };

        std::function<void(std::string ref, int depth)> func;
        func = [&](std::string ref, int depth)->void
        {
            int number = int(digits[depth] - '0' - 2);
            const std::string& map_str_ref = map[number];

            if(depth == digits.size() - 1)
            {
                for(const char c : map_str_ref)
                {
                    ref.back() = c;
                    ret.push_back(ref);
                }
            }
            else
            {
                for(const char c : map_str_ref)
                {
                    ref[depth] = c;
                    func(ref, depth + 1);
                }
            }
        };

        func(digits, 0);
        return ret;
    }
};