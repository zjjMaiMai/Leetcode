/*
题目描述
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        if (pre.empty() || vin.empty())
        {
            return nullptr;
        }

        TreeNode* root = new TreeNode(pre[0]);
        auto it = std::find(vin.begin(), vin.end(), root->val);
        vector<int> left_vin(vin.begin(), it);
        vector<int> right_vin(it + 1, vin.end());
        vector<int> left_pre(pre.begin() + 1, pre.begin() + left_vin.size() + 1);
        vector<int> right_pre(pre.begin() + left_vin.size() + 1, pre.end());

        root->left = reConstructBinaryTree(left_pre, left_vin);
        root->right = reConstructBinaryTree(right_pre, right_vin);

        return root;
    }
};

void tree_pre(TreeNode* head, std::vector<int>& out)
{
    if (head == nullptr)
    {
        return;
    }

    out.push_back(head->val);
    tree_pre(head->left, out);
    tree_pre(head->right, out);
}

void tree_in(TreeNode* head, std::vector<int>& out)
{
    if (head == nullptr)
    {
        return;
    }

    tree_in(head->left, out);
    out.push_back(head->val);
    tree_in(head->right, out);
};

int main(int argc, char* argv[])
{
    std::vector<int> pre = { 1,2,4,7,3,5,6,8 };
    std::vector<int> vin = { 4,7,2,1,5,3,8,6 };

    Solution solution;
    TreeNode* head = solution.reConstructBinaryTree(pre, vin);

    std::vector<int> pre_;
    tree_pre(head, pre_);

    std::vector<int> vin_;
    tree_in(head, vin_);

    assert(pre_ == pre && vin_ == vin);
    return 0;
}
