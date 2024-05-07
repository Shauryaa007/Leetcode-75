// 238. Product of Array Except Self
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int zeros=0;
        int prod=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)zeros++;
            else prod*=nums[i];
        }

        vector<int>ans(n,0);

        for(int i=0;i<n;i++)
        {
            if(zeros==0)
            {
                ans[i]=prod/nums[i];
            }
            if(zeros==1)
            {
                if(nums[i]==0)ans[i]=prod;
            }
        }

        return ans;
    }
};