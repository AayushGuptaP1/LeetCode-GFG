class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        
        int fresh = 0;
        int res = 0;
        queue<pair<pair<int,int>,int>>q;
        
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j]==2)
                    q.push({{i,j},0});
                else if(grid[i][j]==1)
                    fresh++;
            }
        }
        
        while(q.empty()==false)
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            
            res = max(res,time);
            
            if(row-1>=0 && row-1<m && grid[row-1][col]==1 )
            {
                q.push({{row-1,col},time+1});
                grid[row-1][col] = 0;
                fresh--;
            }
            if(row+1>=0 && row+1<m && grid[row+1][col]==1)
            {
                q.push({{row+1,col},time+1});
                grid[row+1][col] = 0;
                fresh--;
            }
            if(col-1>=0 && col-1<n && grid[row][col-1]==1)
            {
                q.push({{row,col-1},time+1});
                grid[row][col-1] = 0;
                fresh--;
            }
            if(col+1>=0 && col+1<n && grid[row][col+1]==1)
            {
                q.push({{row,col+1},time+1});
                grid[row][col+1] = 0;
                fresh--;
            }
        }
        return fresh==0? res : -1;
    }
};