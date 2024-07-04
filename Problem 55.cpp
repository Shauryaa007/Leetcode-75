// 162. Find Peak Element

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)return 0;

        int l=0,h=n-1;
        while(l<h) {
            int mid=l+(h-l)/2;
            if(nums[mid]<nums[mid+1])
                l=mid+1;
            else
                h=mid;
        }
        return l;

    }
};