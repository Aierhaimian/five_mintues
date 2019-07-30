#include <iostream>

using namespace std;

struct TreeNode{
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
        :value(x), left(nullptr), right(nullptr) {}
};

// 题目：已知一棵完全二叉树，求其节点的个数
// 要求：时间复杂度低于O(n)，n为这棵树的节点个数
//
// 计算头节点的右子节点为根节点的树的高度
// 1. 如果此子树的高度+1等于整个树的高度，则整个树的左子树是满二叉树，
//    因此，左子树+根节点的节点数为2^(h-1)-1+1。此时右子树为原问题的
//    子问题，递归解决。
// 2. 如果此子树的高度+1不等于整个树的高度，则整个树的右子树是满二叉树，
//    因此，右子树+根节点的节点数为2^(h-1-1)-1+1。此时左子树为原问题的
//    子问题，递归解决。
//
// 时间复杂度：O((logn)^2)
// 空间复杂度：O(1)
class Solution{
public:
    int countNodes(TreeNode *root) {
        if (root == nullptr)
            return 0;
        return count(root, 1, nodeHigh(root, 1)); // 此处求整棵树高
    }
private:
    int count(TreeNode *root, int level, int h)
    {
        //到了最后一层
        if (level == h)
            return 1;

        //如果右子树高度加1等于数的高度，左子树是满二叉树
        //递归计算右子树
        if (nodeHigh(root->right, level+1) == h) // 此处求右子树的高度
            return (1<<(h-level)) + count(root->right, level+1, h);
        //如果右子树高度加1不等于树的高度，右子树是满二叉树
        //递归计算左子树
        else
            return (1<<(h-level-1)) + count(root->left, level+1, h);
    }
    int nodeHigh(TreeNode *node, int h)
    {
        while(node != nullptr)
        {
            ++h;
            node = node->left;
        }
        return h - 1;
    }
};

int main()
{
    return 0;
}

