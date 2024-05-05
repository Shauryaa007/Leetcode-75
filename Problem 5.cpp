//  345. Reverse Vowels of a String

class Solution {
public:
    bool isVowel(char c) 
    {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
    string reverseVowels(string s) {
        int l=0,r=s.length()-1;
        while(l<=r)
        {
            if(l<=r && isVowel(s[l])&&isVowel(s[r]))
            {
                swap(s[l++],s[r--]);
            }
            if(l>r)break;
            
            if(!isVowel(s[l]))l++;
            if(!isVowel(s[r]))r--;
        }
        return s;
    }
};