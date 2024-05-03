// 1431. Kids With the Greatest Number of Candies

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n=candies.size();
        int maxi=*max_element(candies.begin(),candies.end()); // finding maxCandy

        vector<bool>ans(n);
        
        for(int i=0;i<n;i++)
        {
            if(candies[i]+extraCandies>=maxi)ans[i]=true;
            else ans[i]=false;
        }
        return ans;
    }
};