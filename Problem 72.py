class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals = sorted(intervals,key=lambda x:x[1])
        count=1 # non overlapping
        prev=0  # index of prev interval.
        n= len(intervals)
        for i in range(1,len(intervals)):
            if(intervals[i][0]>=intervals[prev][1]): # non overlapping
                count+=1
                prev =i
        return n-count