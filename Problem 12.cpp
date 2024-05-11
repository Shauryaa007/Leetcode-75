// 11. Container With Most Water

class Solution {
public:
    int maxArea(vector<int>& h) {
        int n=h.size();
        int i=0,j=n-1;
        int maxWater=INT_MIN;

        while(i<j)
        {
            int water=(j-i)*min(h[i],h[j]);
            maxWater=max(maxWater,water);

            if(h[i]<h[j])i++;

            else j--;
        }

        return maxWater;
    }
};