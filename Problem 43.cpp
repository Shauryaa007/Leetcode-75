// 841. Keys and Rooms

class Solution {
public:
    void solve(int room, unordered_map<int,vector<int>>&keys ,vector<int>&vis)
    {
        vis[room]=1;
        for(auto nb: keys[room])
        {
            if(!vis[nb])
            solve(nb,keys,vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        unordered_map<int,vector<int>>keys;

        for(int i=0;i<rooms.size();i++)
        {
            for(int j=0;j<rooms[i].size();j++)
            {
                keys[i].push_back(rooms[i][j]);
            }
        }

        vector<int>vis(n);

        solve(0,keys,vis);

        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)return false;
        }
        return true;
    }

    
};