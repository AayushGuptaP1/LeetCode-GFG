class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int res = -1;
        
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j]==1)
                {
                    visited[i][j] = true;
                    q.push({{i,j},0});
                }
            }
        }
        
        while(q.empty()==false)
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            res = max(res,time);
            
            if(row-1>=0 && row-1<m && visited[row-1][col] == false)
            {
                q.push({{row-1,col},time+1});
                visited[row-1][col] = true;
            }
            if(row+1>=0 && row+1<m && visited[row+1][col] == false)
            {
                q.push({{row+1,col},time+1});
                visited[row+1][col] = true;
            }
            if(col-1>=0 && col-1<n && visited[row][col-1] == false)
            {
                q.push({{row,col-1},time+1});
                visited[row][col-1] = true;
            }
            if(col+1>=0 && col+1<n && visited[row][col+1] == false)
            {
                q.push({{row,col+1},time+1});
                visited[row][col+1] = true;
            }
                
        }
        return res==0? -1 : res;
    }
};