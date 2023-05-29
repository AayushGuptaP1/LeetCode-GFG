class Solution {
private:
    int dfs(int i,int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        if( i>= m  || j>=n || grid[i][j] == 1)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(i == m-1 && j == n-1)
        {
            return 1;
        }
        grid[i][j] = 1;
        
        int left = dfs(i+1,j,grid,dp);
        int right =dfs(i,j+1,grid,dp);
        
        
        grid[i][j] = 0;
        return dp[i][j] = left+right;
        
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) 
    {
        
        int m = grid.size();
        int n = grid[0].size();        
        vector<vector<int>> dp(m, vector<int>(n,-1)); 
        
        
        
        return dfs(0,0,grid,dp);
    }
};