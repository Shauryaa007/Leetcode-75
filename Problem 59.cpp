// 1137. N-th Tribonacci Number

// recursion---

class Solution {
public:
    int tribo(int n)
    {
        if(n==0)return 0;
        if(n==1||n==2)return 1;

        return tribo(n-1)+tribo(n-2)+tribo(n-3);
    }
    int tribonacci(int n) {
        return tribo(n);
    }
};

// Memoization

class Solution {
public:
    int tribo(int n,vector<int>&dp)
    {
        if(n==0)return 0;
        if(n==1||n==2)return 1;

        if(dp[n]!=-1)return dp[n];

        return dp[n]= tribo(n-1,dp)+tribo(n-2,dp)+tribo(n-3,dp);
    }
    int tribonacci(int n) {
        vector<int>dp(n+1,-1);
        return tribo(n,dp);
    }
};

// tabulation

// class Solution {
// public:
//     int tribonacci(int n) {
//        vector<int>dp(n+1,0);  
//         dp[0]=0;
//         dp[1]=1;
//         dp[2]=1;

//         for(int i=3;i<=n;i++)
//         {
//             dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
//         }

//         return dp[n];
//     }
// };


// space optimized BU

class Solution {
public:
    int tribonacci(int n) {
        if(n==0)return  0;
        int p3=0;
        int p2=1;
        int p1=1;

        for(int i=3;i<=n;i++)
        {
            int curr =p1+p2+p3;
            p3=p2;
            p2=p1;
            p1=curr;
        }
        return p1;
    }
};
