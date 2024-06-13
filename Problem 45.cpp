// 1466. Reorder Routes to Make All Paths Lead to the City Zero

class Solution {
public:
int ans=0;
    void dfs(unordered_map<int,vector<int>>&adj ,unordered_map<int,bool>&vis,int city){
        vis[city]=true;

        for(auto nb :adj[city]){
            if(nb>=0){
                if(!vis[nb]){    
                    dfs(adj,vis,nb);
                }
            }
            else{ // -ve neighbour
                nb=abs(nb);
                if(!vis[nb]){   
                    ans++; 
                    dfs(adj,vis,nb);
                }
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& c) {
        int s=c.size();
        unordered_map<int,vector<int>>adj;
        unordered_map<int,bool>vis;

        // [0  ->  1]
        // [+ve   -ve]

        for(int i=0;i<s;i++){
            adj[c[i][1]].push_back(c[i][0]);
            adj[c[i][0]].push_back(-c[i][1]);
        }

        dfs(adj,vis,0);
        return ans;
    }
};