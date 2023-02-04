class Solution {
private: 
    void dfs(int row,int col,int m,int n, vector<vector<int>> &grid)
    {
        if(row<0 || row==m || col<0 || col==n || grid[row][col]!=1)
            return;
        
        grid[row][col] = -1;
        
        dfs(row-1,col,m,n,grid);
        dfs(row+1,col,m,n,grid);
        dfs(row,col-1,m,n,grid);
        dfs(row,col+1,m,n,grid);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int count = 0;
        
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(i==0 || i==m-1 || j==0 || j==n-1)
                    if(grid[i][j] == 1)
                        dfs(i,j,m,n,grid);
            }
        }
        
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j] == 1)
                    count++;
                if(grid[i][j] == -1)
                    grid[i][j] = 1;
            }
        }
        return count;
    }
};