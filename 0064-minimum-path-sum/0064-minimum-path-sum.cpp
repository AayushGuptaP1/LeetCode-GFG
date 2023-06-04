class Solution {

public:
    int minPathSum(vector<vector<int>>& grid) 
    {  
        int m = grid.size();
        int n = grid[0].size();
        vector<int>  curr(n,grid[0][0]);     
        
        for(int i=1;i<n;++i)
        {
            curr[i] = curr[i-1]+ grid[0][i];
        }        
        
        for(int i=1;i<m;++i)
        {
            curr[0] += grid[i][0];
            for(int j=1;j<n;++j)
            {
                curr[j] = min(curr[j], curr[j-1])+ grid[i][j];
            }   
        }
        return curr[n-1];       
    }
};