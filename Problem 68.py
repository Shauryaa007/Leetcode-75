class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        xorr=0
        for num in nums:
            xorr=xorr^num
        return xorr
        
# 0 ^ 5 = 5
 
# 3 ^ 3 =0

#   3 - 1 1
#   3 - 1 1
# 3^3 - 0 0
