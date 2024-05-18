// 1657. Determine if Two Strings Are Close

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();

        if(n!=m)return false;

        map<char,int>m1,m2;

        for(int i=0;i<n;i++)
        {
            m1[word1[i]]++;
            m2[word2[i]]++;
        }

        for(int i=0;i<n;i++)
        {
            if(m1[word2[i]]<=0)return false;
        }

        vector<int>v1,v2;

        for(auto it:m1)v1.push_back(it.second);
        for(auto it:m2)v2.push_back(it.second);

        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());

        return v1==v2;
    }
};