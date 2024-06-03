// 1448. Count Good Nodes in Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* node , int maxi)
    {
        if(node==NULL)return 0;

        if(maxi<=node->val)
        {
            maxi=node->val;
            return solve(node->left,maxi)+solve(node->right,maxi)+1;
        }
        return solve(node->left,maxi)+solve(node->right,maxi);
    }
    int goodNodes(TreeNode* root) {
        int maxi=INT_MIN;
        if(root==NULL)return 0;
        return solve(root,maxi);
    }
};