class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        flip = 0
        while(a or  b or c):
            x=a&1 #lsb
            y=b&1
            z=c&1
            if((x|y)!=z):
                if(x==1 and y==1 and z==0):
                    flip +=2
                else:
                    flip +=1
            a=a>>1
            b=b>>1
            c=c>>1

        return flip