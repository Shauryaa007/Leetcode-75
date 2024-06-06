//  236. Lowest Common Ancestor of a Binary Tree

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p||root==q||!root)return root;

        TreeNode* left= lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);

        if(!left&&!right)return NULL;

        if(left&&right)return root;

        if(left)return left;
        if(right)return right;

        return NULL;//
        //return !left?right: !right?left : root;
    }
};