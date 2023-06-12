class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int res = INT_MAX;
        
        vector<vector<int>> dp(m,vector<int>(m,0));
        
        for(int i=0;i<m;++i)
            dp[0][i] = matrix[0][i];       
        
        for(int i=1;i<m;++i)
        {
            for(int j=0;j<m;++j)
            {
                int leftD = (j>0)? dp[i-1][j-1] : INT_MAX;
                int rightD = (j<m-1)? dp[i-1][j+1] : INT_MAX;
                dp[i][j] = min(dp[i-1][j],min(leftD,rightD)) + matrix[i][j];                
            }
                
        }
        
        for(int i=0;i<m;++i)
            res = min(res, dp[m-1][i]);        
        
        return res;
        
        
        
    }
};