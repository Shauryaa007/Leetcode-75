// 151. Reverse Words in a String

class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        reverse(s.begin(),s.end());
        int st=0,end=0,i=0;

        while(i<n)
        { 
            while(i<n&&s[i]==' ')i++;
            if(i==n)break; // to stop index going out of bounds
            
            while(i<n&&s[i]!=' ')s[end++]=s[i++];

            reverse(s.begin()+st ,s.begin()+end);

            s[end++]=' ';

            st=end;

            i++;
        }
        s.resize(end-1);

        return s;
    }
};