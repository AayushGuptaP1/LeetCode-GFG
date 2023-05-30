class Solution {
private:
    int findPaths(int m, int n, vector<vector<int>> &obstacleGrid,vector<vector<int>> &dp)
    {
        if(m<0 || n<0 || obstacleGrid[m][n] == 1)
            return 0;
        if(m == 0 && n == 0)
            return 1;
        if(dp[m][n] != -1)
            return dp[m][n];
        
        return dp[m][n] = findPaths(m-1,n,obstacleGrid,dp) + findPaths(m,n-1,obstacleGrid,dp);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        return findPaths(m-1,n-1,obstacleGrid,dp);
    }
};