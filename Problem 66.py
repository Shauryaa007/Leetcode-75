# class Solution:
#     def solve(self, w1, w2,i ,j):
#         if(i<0):
#             return j+1
#         if(j<0):
#             return i+1
#         if(w1[i]==w2[j]):
#             return self.solve(w1, w2, i-1, j-1)
        
#         else :
#             #replace
#             replace = self.solve(w1, w2, i-1, j-1)
            
#             #insert
#             insert = self.solve(w1, w2, i, j-1)

#             #delete
#             delete = self.solve(w1, w2, i-1, j)
            
#             return 1+ min(delete,insert,replace)

#     def minDistance(self, w1: str, w2: str) -> int:
#         n1, n2 = len(w1), len(w2)
#         return self.solve(w1,w2,n1-1,n2-1)


# ----- Memoization ------------

# import sys
# class Solution:
#     def solve(self, w1, w2,i ,j,dp):
#         if(i<0):
#             return j+1
#         if(j<0):
#             return i+1

#         if(dp[i][j]!=-1):
#             return dp[i][j]
        
#         if(w1[i]==w2[j]):
#             dp[i][j]=self.solve(w1, w2, i-1, j-1,dp)
#             return dp[i][j]
        
#         else :
#             #replace
#             replace = self.solve(w1, w2, i-1, j-1,dp)
            
#             #insert
#             insert = self.solve(w1, w2, i, j-1,dp)

#             #delete
#             delete = self.solve(w1, w2, i-1, j,dp)
#             dp[i][j] = 1+ min(delete,insert,replace)
#             return dp[i][j]

#     def minDistance(self, w1: str, w2: str) -> int:
#         n1, n2 = len(w1), len(w2)
#         dp = [[-1]*(n2+1) for _ in range(n1+1)]
#         return self.solve(w1,w2,n1-1,n2-1,dp)

# -------- Tabulation ----------

class Solution:
    def minDistance(self, w1: str, w2: str) -> int:
        n1, n2 = len(w1), len(w2)
        dp = [[0]*(n2+1) for _ in range(n1+1)]
        for j in range(n2+1):
            dp[0][j]=j
        for i in range(n1+1):
            dp[i][0]=i
        
        for i in range(1,n1+1):
            for j in range(1,n2+1):
                if w1[i-1]==w2[j-1]:
                    dp[i][j]=dp[i-1][j-1]
                else:
                    dp[i][j]= 1 + min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])
        return dp[n1][n2]

        