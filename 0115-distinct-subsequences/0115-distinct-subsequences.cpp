class Solution {
private:
    int countDistinct(int i, int j, string &s, string &t,vector<vector<int>> &dp)
    {
        if(j==0)
            return 1;
        if(i==0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int notTake = countDistinct(i-1,j,s,t,dp);
        int take = 0;
        if(s[i-1] == t[j-1])
            take =  countDistinct(i-1,j-1,s,t,dp);
        return dp[i][j] = take+notTake;
    }
public:
    int numDistinct(string s, string t)
    {
        int m = s.length();
        int n = t.length();
        vector<vector<double>> dp(m+1,vector<double>(n+1,0));
        for(int i=0;i<=m;++i)
            dp[i][0] = 1;
        
        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                double notTake = dp[i-1][j];
                double take = 0;
                if(s[i-1] == t[j-1])
                    take = dp[i-1][j-1];
                dp[i][j] = take+notTake;
            }
        }
        return(int) dp[m][n];
        
    }
};