class Solution {
private:
    bool canMatch(string &s, string &p, int i, int j,vector<vector<int>> &dp)
    {
        if(i<0 && j<0)
            return true;
        if(i<0 && j>=0)
        {
            for(int k=0;k<=j;++k)
            {
                if(p[k] != '*')
                    return false;
            }
            return true;
        }
        if(j<0)
            return false;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == p[j] || p[j] == '?')
            return dp[i][j] =  canMatch(s,p,i-1,j-1,dp);
        else if(p[j] == '*')
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
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        return canMatch(s,p,m-1,n-1,dp);
    }
};