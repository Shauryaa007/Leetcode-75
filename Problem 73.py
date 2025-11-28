class Solution:
    def findMinArrowShots(self, p: List[List[int]]) -> int:
        p = sorted(p, key = lambda x: (x[1],x[0]))
        prev =0
        count =1 # non overlapping
        print(p)
        
        for i in range(1,len(p)):
            if(p[i][0]>p[prev][1]):
                count+=1
                prev=i
        return count