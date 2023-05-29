class Solution {
private:
    int dfs(int i,int j, vector<vector<int>> &grid, int &count, vector<vector<int>> &dp)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        if( i>= m  || j>=n || grid[i][j] == 1)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(i == m-1 && j == n-1)
        {
            count++;
            return dp[i][j] = count;
        }
        grid[i][j] = 1;
        
        int left = dfs(i+1,j,grid,count,dp);
        int right =dfs(i,j+1,grid,count,dp);
        
        
        grid[i][j] = 0;
        return dp[i][j] = left+right;
        
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) 
    {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();        
        vector<vector<int>> dp(m, vector<int>(n,-1)); 
        
        
        
        return dfs(0,0,grid,count,dp);
    }
};