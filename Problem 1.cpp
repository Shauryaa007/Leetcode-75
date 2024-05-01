// 1768. Merge Strings Alternately

// Solution-

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
       int n=word1.size(),m=word2.size();
       int i=0,j=0;

       string ans="";

       while(i<n&&j<m)
       {
        ans+=word1[i++];
        ans+=word2[j++];
       } 
       if(i<n)ans+=word1.substr(i,n-i);
       if(j<m)ans+=word2.substr(j,m-j);

       return ans;
    }


};