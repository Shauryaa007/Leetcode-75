//104. Maximum Depth of Binary Tree


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)return 0;

        int currDep=1;

        int left=maxDepth(root->left);
        int right=maxDepth(root->right);

        return max(left,right)+currDep;
    }
};