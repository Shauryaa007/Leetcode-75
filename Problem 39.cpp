// 199. Binary Tree Right Side View

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==nullptr) return ans;

       queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            int size=q.size();
            ans.push_back(q.back()->val);

            for(int i=0;i<size;i++)
            {
                TreeNode* front=q.front();
                q.pop();

                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
        }
        return ans;
        
    }
};