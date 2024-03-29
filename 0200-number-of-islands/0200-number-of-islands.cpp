class Solution {
private:
    void bfs(int row, int col,vector<vector<char>> &grid)
    {
        
        int m = grid.size();
        int n = grid[0].size();
        int traverse[5] = {0,-1,0,1,0};
        
        
        queue<pair<int,int>>q;
        q.push({row,col});
        grid[row][col] = '0';
        
        while(q.empty()==false)
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i=0;i<4;++i)
            {
                int dRow = row + traverse[i];
                int dCol = col + traverse[i+1];
                
                if(dRow>=0 && dRow<m && dCol>=0 && dCol<n && grid[dRow][dCol]=='1')
                {
                    q.push({dRow,dCol});
                    grid[dRow][dCol] = '0';
                }
                    
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