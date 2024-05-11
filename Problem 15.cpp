// 1456. Maximum Number of Vowels in a Substring of Given Length

class Solution {
public:
    int isVowel(char ch)
    {
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
        return 1;

        return 0;
    }
    int maxVowels(string s, int k) {
        int n=s.size();
        int st=0;
        int end=k-1;

        int v=0;
        for(int i=st;i<=end;i++)v+= isVowel(s[i]);

        int maxV=v;

        while(end<n-1)
        {
            v+=isVowel(s[++end]);
            v-=isVowel(s[st++]);

            maxV=max(maxV,v);
        }
        return maxV;
    }
};