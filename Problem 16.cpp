//1004. Max Consecutive Ones III


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;

        int maxLen=0;

        while(j<n)
        {
            if(nums[j]==0)k--;

            if(k<0)
            {
                maxLen=max(maxLen, j-i);
                while(i<j&&nums[i]!=0)i++; // shrinking 
                i++;
                k++;
            }

            j++; // expansion
        }
        maxLen=max(maxLen,j-i);
        return maxLen;
    }
};