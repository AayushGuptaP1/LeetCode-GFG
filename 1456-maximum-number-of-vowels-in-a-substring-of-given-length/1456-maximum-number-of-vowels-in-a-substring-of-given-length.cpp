class Solution {
private:
    bool isVowel(const char &c)
    {
        return(c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
public:
    int maxVowels(string s, int k) 
    {
        int i=0,j=0;
        int n = s.length();
        int res = 0;
        int count = 0;
        
        for(j=0;j<k;++j)
        {
            if(isVowel(s[j]))
                count++;
        }
        res = max(count,res);
        
        while(j<n)
        {
            if(isVowel(s[i]))
                count--;
            i++;
            if(isVowel(s[j]))
                count++;
            j++;
            res = max(res,count);
        }
        return res;
        
    }
};