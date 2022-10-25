class Solution {
public:
    int firstUniqChar(string &s)
    {
        vector<int> v(26,-1);
        int n = s.size();
        int res = INT_MAX;
        
        for(int i=0; i<n; ++i)
        {
            if(v[s[i]- 'a'] == -1)
                v[s[i] - 'a'] = i;
            else
                v[s[i] - 'a'] = -2;
        }
        
        for(int i=0 ;i<26;++i)
        {
            if(v[i]>=0)
                res = min(res,v[i]);
        }
        
        return (res == INT_MAX)? -1 : res;
        
    }
        
};