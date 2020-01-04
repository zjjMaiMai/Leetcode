/*
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <assert.h>
#include <limits>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int rev = 0;
        while (x != 0)
        {
            int pop = x % 10;
            x /= 10;

            if (pop > 0 && ((std::numeric_limits<int>::max() - pop) / 10) < rev)
            {
                return 0;
            }
            else if (pop < 0 && ((std::numeric_limits<int>::min() - pop) / 10) > rev)
            {
                return 0;
            }
            else
            {
                rev = rev * 10 + pop;
            }
        }
        return rev;
    }
};

int main(int argv, char *argc[])
{
    Solution solution;
    assert(solution.reverse(123) == 321);
    assert(solution.reverse(-123) == -321);
    assert(solution.reverse(-120) == -21);
}