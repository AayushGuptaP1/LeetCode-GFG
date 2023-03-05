class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        
        if(grid[0][0]==1 || grid[m-1][n-1]==1)
            return -1;
        
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},1});
        visited[0][0] = true;
        
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            if(row==m-1 && col==n-1)
                return time;
            
            for(int i=-1;i<=1;++i)
            {
                for(int j=-1;j<=1;++j)
                {
                    int dRow = row+i;
                    int dCol = col+j;
                    
                    if(dRow>=0 && dRow<m && dCol>=0 && dCol<n && visited[dRow][dCol]==false && grid[dRow][dCol]==0)
                    {
                        q.push({{dRow,dCol},time+1});
                        visited[dRow][dCol] = true;
                    }
                }
            }
        }
        return -1;
        
    }
};