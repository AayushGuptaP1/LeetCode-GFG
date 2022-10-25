class Solution {
public:
    char repeatedCharacter(string &s) 
    {
        vector<int> v(26,0);
        
        
        for(char c : s)
        {
            if(v[c-'a'] != 0)
                return c;
            else
                v[c-'a']++;
        }
        return 'a';
        
    }
};