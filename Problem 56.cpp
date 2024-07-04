// 875. Koko Eating Bananas

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();

        int low=1;
        int high=*max_element(piles.begin(),piles.end());

        int minspeed;

        while(low<=high)
        {
            int mid=(low+high)/2;
            long long tf=0;

            for(int i=0;i<n;i++)
            {
                tf+=piles[i]/mid+(piles[i]%mid!=0);
            }
            
            if(tf>h)
            low=mid+1;
            else 
            {
                minspeed=mid;
                high=mid-1;
            }

        }
        return minspeed;
        
    }
};