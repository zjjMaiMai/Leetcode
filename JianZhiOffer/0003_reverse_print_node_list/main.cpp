/*
题目描述
输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
*/

#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

void insert_value(std::vector<int>& vec, ListNode* node)
{
    if (node)
    {
        if (node->next)
        {
            insert_value(vec, node->next);
        }
        vec.push_back(node->val);
    }
}

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head)
    {
        std::vector<int> ret;
        insert_value(ret, head);
        return ret;
    }
};


int main(int argc, char* argv[])
{
    ListNode* head = new ListNode(0);
    ListNode* it = head;
    for (int i = 0; i < 5; i++)
    {
        it->next = new ListNode(i);
        it = it->next;
    }

    Solution solution;
    auto ret = solution.printListFromTailToHead(head);

    for (const auto& var : ret)
    {
        std::cout << var;
    }
    return 0;
}