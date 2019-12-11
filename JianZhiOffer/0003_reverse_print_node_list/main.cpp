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
    std::vector<int> src = { 1, 2, 3, 4, 5 };

    ListNode* head = new ListNode(1);
    ListNode* node = head;

    for (auto it = src.begin() + 1; it != src.end(); it++)
    {
        if (!node->next)
        {
            node->next = new ListNode(-1);
        }
        node = node->next;
        node->val = *it;
    }

    Solution solution;
    auto ret = solution.printListFromTailToHead(head);
    
    std::reverse(src.begin(), src.end());
    assert(src == ret);
    return 0;
}