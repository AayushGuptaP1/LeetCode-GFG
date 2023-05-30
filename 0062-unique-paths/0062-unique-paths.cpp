class Solution {
private:
    int findPaths(int m, int n, vector<vector<int>> &dp)
    {
         if(m<0 || n<0)
            return 0;   
        if(dp[m][n] != -1)
            return dp[m][n];
        if(m == 0 && n == 0)
            return 1;
        return dp[m][n]=  findPaths(m-1,n,dp) + findPaths(m,n-1,dp);
    }
    
public:
    int uniquePaths(int m, int n) 
    {
//         Combinatorial Solution
//         int N = m+n-2;
//         int R = m-1;
//         double res =1;
        
//         for(int i =1;i<=R;++i)
//         {
//             res = res*(N-R+i)/i;
//         }
//         return (int)res; 
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        return findPaths(m-1,n-1,dp);     
    }
};