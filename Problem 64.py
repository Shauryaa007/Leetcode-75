# class Solution:
#     def solve(self,t1,t2,i,j):
#         if(i<0 or j<0):
#             return 0

#         if t1[i]==t2[j] : # match
#             return 1 + self.solve(t1,t2,i-1,j-1)
#         else: # not match
#             return max(self.solve(t1,t2,i-1,j),self.solve(t1,t2,i,j-1))
        

#     def longestCommonSubsequence(self, text1: str, text2: str) -> int:
#         n1,n2 = len(text1),len(text2)
#         return self.solve(text1,text2,n1-1,n2-1)

# ------- Memoization ----

# class Solution:
#     def solve(self,t1,t2,i,j,dp):
#         if(i<0 or j<0):
#             return 0
#         if dp[i][j]!=-1 :
#             return dp[i][j]

#         if t1[i]==t2[j] :
#             dp[i][j] = 1 + self.solve(t1,t2,i-1,j-1,dp)
#             return dp[i][j]
#         else:
#             dp[i][j] = 0 + max(self.solve(t1,t2,i-1,j,dp),self.solve(t1,t2,i,j-1,dp))
#             return dp[i][j]
        

#     def longestCommonSubsequence(self, text1: str, text2: str) -> int:
#         n1,n2 = len(text1),len(text2)
#         dp = [[-1]*(n2+1) for _ in range(n1+1)]

#         return self.solve(text1,text2,n1-1,n2-1,dp)

# ---------Bottom up (tabulation)-------------------
     
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        n1,n2 = len(text1),len(text2)
        dp = [[0]*(n2+1) for _ in range(n1+1)]

        for i in range(1,n1+1):
            for j in range(1,n2+1):
                if text1[i-1]==text2[j-1]:
                    dp[i][j]=dp[i-1][j-1]+1
                else:
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1])
        
        return dp[n1][n2]
        