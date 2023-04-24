class Solution {
private:
    void dfs(int i,int j, vector<vector<int>> &grid, int canWalk, int &count)
    {
        if(i<0 || i>= grid.size() || j<0 || j>=grid[0].size()||grid[i][j] == -1)
            return;
        --canWalk;
        if(grid[i][j] == 2)
        {
            if(canWalk == 0)
                ++count;
            return;
        }
        grid[i][j] = -1;
        
        dfs(i-1,j,grid,canWalk,count);
        dfs(i+1,j,grid,canWalk,count);
        dfs(i,j-1,grid,canWalk,count);
        dfs(i,j+1,grid,canWalk,count);
        grid[i][j] = 0;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        
        int start_x,start_y;
        
        int canWalk = m*n;
        int count = 0;
        
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j] == -1)
                    --canWalk;
                if(grid[i][j] == 1)
                {
                    start_x = i, start_y =j;
                }
            }
        }     
        dfs(start_x,start_y,grid,canWalk,count);            
        
        return count;
    }
};