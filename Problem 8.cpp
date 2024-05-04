// 334. Increasing Triplet Subsequence

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0);

        int n= nums.size();
        vector<int>prev(n,nums[0]);
        vector<int>post(n,nums[n-1]);

        for(int i=1;i<n;i++)
        {
            prev[i]=min(prev[i-1],nums[i]);
            post[n-1-i]=max(post[n-i],nums[n-1-i]);
        }

        for(int j=1;j<n-1;j++)
        {
            if(nums[j]>prev[j]&&nums[j]<post[j])return true;
        }

        return false;
    }
};