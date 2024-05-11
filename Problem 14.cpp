// 643. Maximum Average Subarray I

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int st=0;
        int end=k-1;
        double sum=0;
        for(int i=st;i<=end;i++)sum+=nums[i];

        double maxSum=sum;

        while(end<nums.size()-1){
           sum+=nums[++end];
           sum-=nums[st++];

           maxSum=max(sum,maxSum);
        }
        return maxSum/k;
    }
};