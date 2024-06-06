// 1372. Longest ZigZag Path in a Binary Tree


class Solution {
public:
    int pathLen;
    void solve(TreeNode* node, int count, int dir)
    {
        if(!node)return ;
        pathLen=max(pathLen,count);

        if(dir==0)
        {
            solve(node->left,count+1,1);
            solve(node->right,1,0);
        }
        else
        {
            solve(node->right,count+1,0);
            solve(node->left,1,1);
        }
    }
    int longestZigZag(TreeNode* root) {
        pathLen=0;

        solve(root->left,1,1);
        solve(root->right,1,0);

        return pathLen;
    }
};