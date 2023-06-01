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
        vector<vector<int>> dp(m, vector<int>(n,-1));
        
        
        return findPath(m-1,n-1,grid,dp);
        
    }
};