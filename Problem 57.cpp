// 17. Letter Combinations of a Phone Number

class Solution {
public:
    void solve(string s,int idx, string digits, unordered_map<char,vector<char>>&mp,vector<string>&ans)
    {
        if(idx==digits.size())ans.push_back(s);
        for(int i=0;i<mp[digits[idx]].size();i++)
        {
            s+=mp[digits[idx]][i];
            solve(s,idx+1,digits,mp,ans);
            s=s.substr(0,s.size()-1);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return {};
        unordered_map<char,vector<char>>mp;

        char x='a';
        for(char i='2';i<='9';i++)
        {
            if(i=='7'||i=='9')
            {
                for(int j=0;j<4;j++)
                {
                    mp[i].push_back(x++);
                }
            }
            else
            {
                for(int j=0;j<3;j++)
                {
                    mp[i].push_back(x++);
                }
            }
        }

        vector<string>ans;
        int idx=0;
        
        string s="";

        solve(s,idx,digits,mp,ans);

        return ans;
    }
};