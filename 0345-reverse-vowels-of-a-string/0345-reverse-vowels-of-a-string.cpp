class Solution {
public:
    string reverseVowels(string &s) 
    {
        int begin = 0;
        int end = s.length()-1;
        
        while(begin < end)
        {
            while(begin < end && !isVowel(s[begin]))
                begin++;
            while(begin < end && !isVowel(s[end]))
                end--;
            swap(s[begin],s[end]);
            begin++,end--;
        }
        return s;
    
    }
    
    bool isVowel(char &c)
    {
        return(c=='a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
};