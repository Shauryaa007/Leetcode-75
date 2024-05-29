// 1493. Longest Subarray of 1's After Deleting One Element

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int k=0;
        int n=nums.size();
        int i=0,j=0;

        int maxLen=0;

        while(j<n)
        {
            if(nums[j]==0)k++;

            if(k>1)
            {
                maxLen=max(maxLen, j-i);
                while(i<j&&nums[i]!=0)i++; // shrinking 
                i++;
                k--;
            }

            j++; // expansion
        }
        maxLen=max(maxLen,(j-i));
        return maxLen-1;
    }
};