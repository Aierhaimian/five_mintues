#include <iostream>
#include <stack>

using namespace std;

struct TreeNode{
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
        :value(x), left(nullptr), right(nullptr) {}
};

// 求二叉树的最大深度
// 先序遍历 Depth
// 递归与非递归实现
class Solution{
public:
    int maxDepthRecur(TreeNode *root)
    {
        if (root== nullptr)
            return 0;
        return 1 + max(maxDepthRecur(root->left), maxDepthRecur(root->right));
    }

    int maxDepthNonRecur(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int depth = 0;
        stack<pair<TreeNode*, int>> stk;
        stk.push(make_pair(root, 1));
        while (!stk.empty())
        {
            TreeNode *cur = stk.top().first;
            int curDepth = stk.top().second;
            stk.pop();

            if (cur->left == nullptr && cur->right == nullptr)
                depth = max(depth, curDepth);
            else
            {
                if (cur->left)
                    stk.push(make_pair(cur->left, curDepth + 1));
                if (cur->right)
                    stk.push(make_pair(cur->right, curDepth + 1));
            }
        }
        return depth;
    }
};


int main()
{
    return 0;
}

