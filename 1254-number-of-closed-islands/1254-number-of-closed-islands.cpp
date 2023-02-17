class Solution {
     private:
    void dfs(int row, int col,vector<vector<int>>& matrix,vector<vector<bool>> &visited )
    {
        int m = matrix.size();
        int n = matrix[0].size();
        
        if(row<0 || row>=m || col<0 || col>=n || visited[row][col]!=false || matrix[row][col]!=0)
        return;
        
        visited[row][col] = true;
        dfs(row-1,col,matrix,visited);
        dfs(row+1,col,matrix,visited);
        dfs(row,col+1,matrix,visited);
        dfs(row,col-1,matrix,visited);
        
        
    }
public:
    int closedIsland(vector<vector<int>>& matrix)
    {
        int M = matrix.size();
        int N = matrix[0].size();
        vector<vector<bool>> visited(M,vector<bool>(N));
        int count = 0;
        for(int i=0;i<M;++i)
        {
            for(int j=0;j<N;++j)
            {
                if(i==0 || i==M-1 || j==0 || j== N-1)
                {
                    if(visited[i][j]==false && matrix[i][j]==0)
                    dfs(i,j,matrix,visited);
                }
            }
        }
        
        for(int i=0;i<M;++i)
        {
            for(int j=0;j<N;++j)
            {
                if(visited[i][j]==false && matrix[i][j]==0)
                {
                    ++count;
                    dfs(i,j,matrix,visited);
                }
            }
        }
        return count;
    }
};