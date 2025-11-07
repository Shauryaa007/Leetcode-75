# class Solution:
#     def count(self,n):
#         c=0
#         while(n!=0):
#             n=n&(n-1)
#             c+=1
#         return c
#     def countBits(self, n: int) -> List[int]:
#         ans=[]
#         for i in range(0,n+1):
#             b = self.count(i)
#             ans.append(b)
#         return ans


class Solution:
    def count(self,n):
        return bin(n).count('1')
    def countBits(self, n: int) -> List[int]:
        ans=[]
        for i in range(0,n+1):
            b = self.count(i)
            ans.append(b)
        return ans