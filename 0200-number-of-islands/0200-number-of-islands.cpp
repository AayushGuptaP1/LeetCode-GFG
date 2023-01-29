class Solution {
private:
    void bfs(int row, int col,vector<vector<char>> &grid)
    {
        
        int m = grid.size();
        int n = grid[0].size();
        
        
        queue<pair<int,int>>q;
        q.push({row,col});
        grid[row][col] = '0';
        
        while(q.empty()==false)
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            if(row-1>=0 && row-1<m && grid[row-1][col]=='1')
            {
                q.push({row-1,col});
                grid[row-1][col] = '0';
            }
            if(row+1>=0 && row+1<m && grid[row+1][col]=='1')
            {
                q.push({row+1,col});
                grid[row+1][col] = '0';
            }
            if(col-1>=0 && col-1<n && grid[row][col-1]=='1')
            {
                q.push({row,col-1});
                grid[row][col-1] = '0';
            }
            if(col+1>=0 && col+1<n && grid[row][col+1]=='1')
            {
                q.push({row,col+1});
                grid[row][col+1] = '0';
            }
                
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        
        
        
        for(int row = 0; row<m; row++)
        {
            for(int col = 0; col<n; col++)
            {
                if(grid[row][col] == '1' )
                {
                    count++;
                     bfs(row,col,grid);
                }
                   
            }
        }
        return count;
    }
};