// 2352. Equal Row and Column Pairs

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map< vector<int>,int>mp;

        for(int i=0;i<grid.size();i++)
        {
            mp[grid[i]]++;
        }

        int count=0;

        for(int c=0;c<grid.size();c++)
        {
            vector<int>temp;
            for(int r=0;r<grid.size();r++)
            {
                temp.push_back(grid[r][c]);
            }
            
            if(mp.find(temp)!=mp.end())
            {
                count+=mp[temp];
            }
        }

        return count;
    }
};