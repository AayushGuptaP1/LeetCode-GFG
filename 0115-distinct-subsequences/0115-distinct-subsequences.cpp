class Solution {
private:
    int countDistinct(int i, int j, string &s, string &t,vector<vector<int>> &dp)
    {
        if(j<0)
            return 1;
        if(i<0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int notTake = countDistinct(i-1,j,s,t,dp);
        int take = 0;
        if(s[i] == t[j])
            take =  countDistinct(i-1,j-1,s,t,dp);
        return dp[i][j] = take+notTake;
    }
public:
    int numDistinct(string s, string t)
    {
        int m = s.length();
        int n = t.length();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return countDistinct(m-1,n-1,s,t,dp);
        
    }
};