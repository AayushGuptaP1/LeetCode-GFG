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
        int res=0;
        
        while(i<j)
        {
            if(isVowel(s[i]))
                res++;
            if(isVowel(s[j]))
                res--;
            i++,j--;
        }
        return res==0;
    }
};