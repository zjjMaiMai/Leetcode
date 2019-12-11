/*
题目描述
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/

#include <iostream>
#include <vector>
#include <stack>
#include <assert.h>

using namespace std;

class Solution
{
public:
    void push(int node)
    {
        stack1.push(node);
    }

    int pop()
    {
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        auto ret = stack2.top();
        stack2.pop();
        return ret;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main(int argc, char* argv[])
{
    std::vector<int> src = { 1, 2, 3, 4, 5 };
    std::vector<int> dst;

    Solution solution;
    for (int i = 0; i < 3; i++)
    {
        solution.push(src[i]);
    }
    for (int i = 0; i < 2; i++)
    {
        dst.push_back(solution.pop());
    }
    for (int i = 3; i < src.size(); i++)
    {
        solution.push(src[i]);
    }
    for (int i = 2; i < src.size(); i++)
    {
        dst.push_back(solution.pop());
    }
    assert(src == dst);
}