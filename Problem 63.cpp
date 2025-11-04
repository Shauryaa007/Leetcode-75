// Recursion.

class Solution {
public:
    int solve(int x, int y)
    {
        if(x<0||y<0)return 0;
        if(x==0||y==0) return 1;    // if(x==0&&y==0)return 1;
        int up = solve(x-1,y);
        int left = solve(x,y-1);

        return up + left;
    }
    int uniquePaths(int m, int n) {
        return solve(m-1,n-1);
    }
};

//  Memoization

class Solution {
public:
    int solve(int x, int y,vector<vector<int>>&dp)
    {
        if(x<0||y<0)return 0;
        if(x==0||y==0) return 1;    // if(x==0&&y==0)return 1; 

        if(dp[x][y]!=-1)return dp[x][y];

        int up = solve(x-1,y,dp);
        int left = solve(x,y-1,dp);

        return dp[x][y]= up + left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,dp);
    }
};

//  tabulation

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0][0]=1;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i-1>=0)dp[i][j]+=dp[i-1][j]; // up
                if(j-1>=0)dp[i][j]+=dp[i][j-1];  //left
                
            }
        }
        return dp[m-1][n-1];
    }
};