//994. Rotting Oranges

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int fresh = 0, time = 0;
        queue<pair<int, int>>q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    // push into queue
                    q.push({i, j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        if(fresh == 0) return 0;
        
        // start BFS traversal
        while(!q.empty()){
            
            int size_q = q.size();
            int temp = 0;// flag check rotting....
            while(size_q--){
                
                pair<int, int>p = q.front();
                q.pop();
                
                int x1 = p.first;
                int y1 = p.second;
                
                int ax[4] = { 1, -1, 0, 0};
                int ay[4] = { 0, 0 , 1 , -1};
                
                for(int i=0; i<4; i++){
                    int x = ax[i] + x1;
                    int y = ay[i] + y1;
                    
                    if(x>=0 && x<n && y>=0 && y<m && grid[x][y] == 1){
                        temp=1;
                        grid[x][y] = 2;//rott
                        q.push({x, y}); // next level
                    }
                }
                
                
            }
            if(temp != 0) time++;
        }
        
        
        
        // we checked if any fresh oranges are still there
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        
        
        
        return time;
    }
};