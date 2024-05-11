// 1679. Max Number of K-Sum Pairs

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();

        int i=0,j=n-1;
        int count=0;

        while(i<j)
        {
            if(nums[i]+nums[j]==k)
            {
                count++;
                i++;
                j--;
            }
            if(nums[i]+nums[j]<k)
            {
                i++;
            }
            if(nums[i]+nums[j]>k)
            {
                j--;
            }
        }

        return count;
    }
};