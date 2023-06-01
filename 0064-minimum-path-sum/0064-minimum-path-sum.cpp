class Solution {
private:
    int findPath(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if(i<0 || j<0)
            return INT_MAX;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(i ==0 && j==0)
            return grid[i][j];
        
        return dp[i][j] = min(findPath(i-1,j,grid,dp), findPath(i,j-1,grid,dp))+ grid[i][j];
    }
public:
    int minPathSum(vector<vector<int>>& grid) 
    {  
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        
        dp[0][0] = grid[0][0];
        
        
        for(int i=1;i<m;++i)
        {
            dp[i][0] = grid[i][0]+dp[i-1][0];
        }
        for(int j=1;j<n;++j)
        {
            dp[0][j] = grid[0][j]+dp[0][j-1];
        }
        
        for(int i=1;i<m;++i)
        {
            for(int j=1;j<n;++j)
            {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1])+ grid[i][j];
            }
        }
        return dp[m-1][n-1];
        
        
        return findPath(m-1,n-1,grid,dp);
        
    }
};