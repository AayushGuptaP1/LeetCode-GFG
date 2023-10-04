class Solution {
private:
    bool canMatch(string &s, string &p, int i, int j,vector<vector<int>> &dp)
    {
        if(i==0 && j==0)
            return true;
        if(j==0 && i>0)
            return false;
        if(i==0 && j>0)
        {
            for(int k=1;k<=j;++k)
            {
                if(p[k-1] != '*')
                    return false;
            }
            return true;
        }
        
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i-1] == p[j-1] || p[j-1] == '?')
            return dp[i][j] =  canMatch(s,p,i-1,j-1,dp);
        else if(p[j-1] == '*')
        {
            bool take = canMatch(s,p,i,j-1,dp);
            bool notTake = canMatch(s,p,i-1,j,dp);
            return dp[i][j] =take | notTake;
        }
        else
            return dp[i][j] =  false;
    }
public:
    bool isMatch(string s, string p) 
    {
        int m = s.length();
        int n = p.length();
        vector<bool>prev(n+1,false), curr(n+1,false);
        prev[0] = true;
        for(int j=1;j<=n;++j)
        {
            if(p[j-1] == '*')
                prev[j] = true;
            else
                break;
        }
        
         for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
                {
                    if(s[i-1] == p[j-1] || p[j-1] == '?')
                        curr[j] =  prev[j-1];
                    else if(p[j-1] == '*')
                    {
                        bool take = curr[j-1];
                        bool notTake = prev[j];
                        curr[j] =take | notTake;
                    }
                    else
                        curr[j] =  false;
                }
                prev = curr;
        }
        
        
        return prev[n];
    }
};