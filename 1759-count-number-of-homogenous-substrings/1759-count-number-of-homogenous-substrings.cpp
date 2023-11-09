class Solution {
int MOD = 1e9+7;
public:
    int countHomogenous(string s)
    {
        int n = s.length();
        vector<int> res(n,1);
        int ans = 1;
        
        for(int i=1;i<n;++i)
        {
            if(s[i] == s[i-1])
                res[i] += res[i-1]%MOD;
            ans += res[i]%MOD;
            ans = ans%MOD;
            
        }
        return ans;
    }
};