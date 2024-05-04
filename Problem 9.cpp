//443. String Compression

class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int index=0;
        int i=0;

        while(i<n)
        {
            char c=chars[i];
            int count=0;
            while(i<n&&chars[i]==c)
            {
                i++;
                count++;
            }

            chars[index++]=c;
            if(count>1)
            {
                string s=to_string(count);

                for(int i=0;i<s.length();i++)
                {
                    chars[index++]=s[i];
                }
            }
            
        }

        return index;
        
    }
};