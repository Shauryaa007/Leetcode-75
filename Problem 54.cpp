// 2300. Successful Pairs of Spells and Potions

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        int m= potions.size();

        sort(potions.begin(),potions.end());

        vector<int>ans(n);

        for(int i=0;i<n;i++)
        {
            long long spell=spells[i];

            int l=0;
            int h=m-1;

            while(l<h)
            {
                int mid=l+(h-l)/2;
                if(spell*potions[mid]>=success)
                {
                    h=mid-1;
                }
                else
                l=mid+1;
            }
            if(spell*potions[l]>=success)ans[i]=m-l;
            else ans[i]=m-l-1;

        }

        return ans;
    }
};