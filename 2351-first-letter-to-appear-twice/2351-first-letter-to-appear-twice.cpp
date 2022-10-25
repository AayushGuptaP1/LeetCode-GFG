class Solution {
public:
    char repeatedCharacter(string &s) 
    {
        vector<int> v(26,0);
        int n = s.size();
        
        for(int i=0;i<n;++i)
        {
            if(v[s[i]-'a'] == 0)
                v[s[i]-'a']++;
            else
                return s[i];
                
        }
        return 'a';
        
    }
};