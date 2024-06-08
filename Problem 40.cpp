//1161. Maximum Level Sum of a Binary Tree


class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);

        int maxSum=INT_MIN;
        int minLevel=0;
        int level=0;

        while(!q.empty())
        {
            int size=q.size();
            int sum=0;
            for(int i=0;i<size;i++)
            {
                TreeNode* front= q.front();
                q.pop();

                sum+=front->val;

                if(front->left)q.push(front->left);
                if(front->right)q.push(front->right);
            }
            level++;

            if(sum>maxSum)
            {
                minLevel=level;
                maxSum=sum;
            }
        }

        return minLevel;
    }
};