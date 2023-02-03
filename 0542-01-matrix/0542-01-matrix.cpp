class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<bool>>visited(m,vector<bool>(n));
        
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(mat[i][j]==0)
                {
                    q.push({{i,j},0});
                    visited[i][j] = true;                    
                }                 
            }
        }
        
        while(q.empty()==false)
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            
            if(row-1>=0 && row-1<m && visited[row-1][col]==false)
            {
                mat[row-1][col] = time+1;
                visited[row-1][col] = true;
                q.push({{row-1,col},time+1});
                
            }
            if(row+1>=0 && row+1<m && visited[row+1][col]==false)
            {
                mat[row+1][col] = time+1;
                visited[row+1][col] = true;
                q.push({{row+1,col},time+1});
                
            }
            if(col-1>=0 && col-1<n && visited[row][col-1]==false)
            {
                mat[row][col-1] = time+1;
                visited[row][col-1] = true;
                q.push({{row,col-1},time+1});
                
            }
            if(col+1>=0 && col+1<n && visited[row][col+1]==false)
            {
                mat[row][col+1] = time+1;
                visited[row][col+1] = true;
                q.push({{row,col+1},time+1});
                
            }
        }
        return mat;
        
        
    }
};