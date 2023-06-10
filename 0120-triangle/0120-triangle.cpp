class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        int m = triangle.size();
        vector<vector<int>> dp(m,vector<int>(m,0));
        dp[0][0] = triangle[0][0];
        int res = INT_MAX;
        
        for(int i=1;i<m;++i)
        {
            dp[i][0] = dp[i-1][0] + triangle[i][0];
            dp[i][i] = dp[i-1][i-1] + triangle[i][i];
        }
        
        for(int i=1;i<m;++i)
        {
            for(int j=1;j<i;++j)
            {
                dp[i][j] = min(dp[i-1][j-1],dp[i-1][j]) + triangle[i][j];
            }
        }
        
        for(int i=0;i<m;++i)
        {
            res = min(res, dp[m-1][i]);
        }
        return res;
    }
};