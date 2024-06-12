// 547. Number of Provinces

class Solution {
public:
    void solve(int city, vector<vector<int>>&adj, vector<int>&vis)
    {
        vis[city]=1;

        for(auto nc: adj[city])
        {
            if(!vis[nc])
            solve(nc,adj,vis);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]&& i!=j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
                
            }
        }

        int count=0;

        vector<int>vis(n,0);

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                solve(i,adj,vis);
                count++;
            }
        }

        return count;
    }
};