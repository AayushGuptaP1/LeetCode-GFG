class Solution {
private:
    int bfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited)
    {
        int m = grid.size();
        int n = grid[0].size();
        visited[i][j] = true;        
        queue<pair<int,int>> q;
        int traverse[5] = {0,-1,0,1,0};
        int count = 0;
        q.push({i,j});
        
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            ++count;
            
            for(int i=0;i<4;++i)
            {
                int dRow = row + traverse[i];
                int dCol = col + traverse[i+1];
                
                if(dRow>=0 && dRow<m && dCol>=0 && dCol<n && grid[dRow][dCol]==1 && visited[dRow][dCol]==false)
                {
                    q.push({dRow,dCol});
                    visited[dRow][dCol] = true;
                }
            }
        }
        return count;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> visited(m,vector<bool>(n));
        int maxArea = 0;
        
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j] == 1 && visited[i][j] == false)
                {
                    maxArea = max(maxArea,bfs(i,j,grid,visited));
                }
            }
        }
        return maxArea;
    }
};