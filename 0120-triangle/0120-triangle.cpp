class Solution {
private:
    int findMin(int m, int n, vector<vector<int>> &triangle,vector<vector<int>> &dp)
    {
        if(n<0 ||n == triangle[m].size() )
            return INT_MAX;
        
        if(m == 0)
            return triangle[0][0];
        if(dp[m][n] != -1)
            return dp[m][n];
        
        return dp[m][n] =  min(findMin(m-1,n-1,triangle,dp),findMin(m-1,n,triangle,dp))+ triangle[m][n];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        int m = triangle.size();
        int n = triangle[m-1].size();        
        int res = INT_MAX;
        vector<vector<int>> dp(m, vector<int>(n,-1));
        
        for(int i=0;i<n;++i)
        {
            res = min(res, findMin(m-1,i,triangle,dp));
        }
        return res;        
    }
};