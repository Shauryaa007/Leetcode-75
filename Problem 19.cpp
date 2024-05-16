// 724. Find Pivot Index

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();

        vector<int>prefix(n);
        vector<int>suffix(n);

        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];

        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+nums[i];
            suffix[n-i-1]=suffix[n-i]+nums[n-i-1];
        }

        for(int i=0;i<n;i++)
        {
            if(prefix[i]==suffix[i])return i;
        }

        return -1;

    }
};