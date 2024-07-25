//   198. House Robber

class Solution {
public:
    int rob(vector<int>& nums) {

        int notrob=0;
        int rob=0;

        for(int i=0;i<nums.size();i++)
        {
            int newrob;
            int newnotrob;
            newnotrob=max(notrob,rob);
            newrob=notrob+nums[i];

            rob=newrob;
            notrob=newnotrob;
        }

        return max(rob,notrob);
        
    }
};