class Solution {
private:
    double dfs(int row, int column, int k,int n,double dep,vector<vector<vector<double>>> &dp)
    {
        if(row<0 || row>=n || column <0 || column>=n )
            return 0.0;
        if(k == 0)
            return dep;
        if(dp[row][column][k] != -1.0)
            return dp[row][column][k];
        double res = 0.0;
        
        res += dfs(row-1,column-2,k-1,n,dep/8.0,dp);
        res += dfs(row-2,column-1,k-1,n,dep/8.0,dp);
        res += dfs(row-2,column+1,k-1,n,dep/8.0,dp);
        res += dfs(row-1,column+2,k-1,n,dep/8.0,dp);
        res += dfs(row+1,column+2,k-1,n,dep/8.0,dp);
        res += dfs(row+2,column+1,k-1,n,dep/8.0,dp);
        res += dfs(row+2,column-1,k-1,n,dep/8.0,dp);
        res += dfs(row+1,column-2,k-1,n,dep/8.0,dp);
        
        return dp[row][column][k]= res;
    }
public:
    double knightProbability(int n, int k, int row, int column) 
    {
        vector<vector<vector<double>>> dp(n,vector<vector<double>>(n,vector<double>(k+1,-1)));
         return dfs(row,column,k,n,1.0,dp);       
    }
};