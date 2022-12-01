class Solution {
public:
    bool isVowel(char &a)
    {
        if (a >= 'A' && a <= 'Z')
       a += 'a' - 'A';   
 
    return(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u');
    }
    bool halvesAreAlike(string s) 
    {
        int  i =0, j = s.length()-1;
        int left = 0, right = 0;
        
        while(i<j)
        {
            if(isVowel(s[i]))
                left++;
            if(isVowel(s[j]))
                right++;
            i++,j--;
        }
        return left==right;
    }
};