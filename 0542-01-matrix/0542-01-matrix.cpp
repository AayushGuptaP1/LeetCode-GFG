class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int,int>>q;
        vector<vector<bool>>visited(m,vector<bool>(n));
        
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                    visited[i][j] = true;                    
                }                 
            }
        }
        
        while(q.empty()==false)
        {
            int row = q.front().first;
            int col = q.front().second;
            
            q.pop();
            
            if(row-1>=0 && row-1<m && visited[row-1][col]==false)
            {
                mat[row-1][col] = mat[row][col]+1;
                visited[row-1][col] = true;
                q.push({row-1,col});
                
            }
            if(row+1>=0 && row+1<m && visited[row+1][col]==false)
            {
                mat[row+1][col] = mat[row][col]+1;
                visited[row+1][col] = true;
                q.push({row+1,col});
                
            }
            if(col-1>=0 && col-1<n && visited[row][col-1]==false)
            {
                mat[row][col-1] = mat[row][col]+1;
                visited[row][col-1] = true;
                q.push({row,col-1});
                
            }
            if(col+1>=0 && col+1<n && visited[row][col+1]==false)
            {
                mat[row][col+1] = mat[row][col]+1;
                visited[row][col+1] = true;
                q.push({row,col+1});
                
            }
        }
        return mat;
        
        
    }
};