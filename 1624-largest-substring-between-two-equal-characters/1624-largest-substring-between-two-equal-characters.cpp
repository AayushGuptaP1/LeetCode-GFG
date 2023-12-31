class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        vector<int> v(26,-1);
        int res = -1;
        int n = s.length();
        
        for(int i=0;i<n;++i)
        {
            int find = v[s[i] - 'a'];
            if(find != -1)
                res = max(res, i-find-1);
            else            
            v[s[i]-'a'] = i;
        }
        return res;
        
        
        
        
    }
};