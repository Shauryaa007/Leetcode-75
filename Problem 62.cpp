class Solution {
public:
    int mod=1000000007;
    int numTilings(int n) {
        if(n<=2)return n;
        if(n==3)return 5;
        int a=1,b=2,c=5;
        for(int i=4;i<=n;i++)
        {
            int x=((2*c)%mod+a)%mod;
            a=b;b=c;c=x;
        }
        return c%mod;
    }
};