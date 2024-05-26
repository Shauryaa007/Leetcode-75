//394. Decode String

class Solution {
public:
    string decodeString(string s) {
        stack<int>num;
        stack<string>str;
        int n=0;
        string chunk="";

        for(int i=0;i<s.length();i++)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                n=n*10+(s[i]-'0');
            }
            if(s[i]>='a'&&s[i]<='z')
            {
                chunk+=s[i];
            }
            if(s[i]=='[')
            {
                num.push(n);
                str.push(chunk);
                n=0;
                chunk="";
            }
            if(s[i]==']')
            {
                int rep=num.top();
                num.pop();
                string temp=chunk;
                for(int i=1;i<rep;i++)
                {
                    chunk+=temp;
                }
                if(!str.empty())
                chunk=str.top()+chunk;
                str.pop();
            }
        }

        return chunk;
    }
};