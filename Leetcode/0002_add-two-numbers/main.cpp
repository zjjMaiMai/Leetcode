/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <assert.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        if (!(l1 || l2))
        {
            return nullptr;
        }

        ListNode* head = nullptr;
        ListNode** it = &head;
        int decay = 0;
        do
        {
            int sum = 0;
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            sum += decay;
            decay = sum / 10;
            sum = sum % 10;

            if (*it == nullptr)
            {
                *it = new ListNode(-1);
            }
            (*it)->val = sum;
            it = &((*it)->next);
        } while (l1 || l2 || decay);

        return head;
    }
};

ListNode* int_to_list(int value)
{
    std::string value_str = std::to_string(value);
    std::reverse(value_str.begin(), value_str.end());

    ListNode* head = nullptr;
    ListNode** it = &head;

    for (const auto& var : value_str)
    {
        if (*it == nullptr)
        {
            *it = new ListNode(-1);
        }
        (*it)->val = var - '0';
        it = &((*it)->next);
    }
    return head;
}

int list_to_int(ListNode* head)
{
    int ret = 0;
    int mul = 1;
    while (head)
    {
        ret += head->val * mul;
        head = head->next;
        mul *= 10;
    }
    return ret;
}

int main(int argv, char* argc[])
{
    ListNode* a = int_to_list(999);
    ListNode* b = int_to_list(9999);

    Solution solution;
    assert(list_to_int(solution.addTwoNumbers(a, b)) == 999 + 9999);
    return 0;
}