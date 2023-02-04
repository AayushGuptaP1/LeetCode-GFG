class Solution {
private:
    void dfs(int row,int col, int m, int n, vector<vector<char>> &board)
    {
        if(row<0 || row==m || col<0 || col==n || board[row][col] != 'O')
            return;
        
        board[row][col]  = '#';
        
        dfs(row-1,col,m,n,board);
        dfs(row+1,col,m,n,board);
        dfs(row,col-1,m,n,board);
        dfs(row,col+1,m,n,board);
    }
public:
    void solve(vector<vector<char>>& board) 
    {
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(i==0 || i==m-1 || j==0 || j==n-1)
                {
                    if(board[i][j] == 'O')
                        dfs(i,j,m,n,board);
                }
            }
        }
        
         for(int i=0;i<m;++i)
        {
             for(int j=0;j<n;++j)
             {
                 if(board[i][j] == 'O')
                     board[i][j] = 'X';
                 if(board[i][j] == '#')
                     board[i][j] = 'O';
             }
        }
            
    }
};