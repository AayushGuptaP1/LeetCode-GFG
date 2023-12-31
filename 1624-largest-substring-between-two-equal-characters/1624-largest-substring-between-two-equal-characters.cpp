class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        vector<int> v(26,-1);
        int res = -1;
        int n = s.length();
        
        for(int i=0;i<n;++i)
        {
            if(v[s[i] - 'a'] != -1)
                res = max(res, i-v[s[i]-'a']-1);
            else            
            v[s[i]-'a'] = i;
        }
        return res;
        
        
        
        
    }
};