class Solution {
private:
    
    void placeQueens(int n,int col,vector<string> &board, vector<vector<string>> &ans,vector<int> &leftRow,vector<int> &leftDiagonal,vector<int> &rightDiagonal)
    {
        if(col == n)
        {
            ans.push_back(board);
            return;
        }
        
        for(int row = 0;row<n;++row)
        {
            if(leftDiagonal[n-1+col-row] == 0 && rightDiagonal[row+col] == 0 && leftRow[row] == 0 )
            {
                leftRow[row] = 1;
                leftDiagonal[n-1 + col-row] = 1;
                rightDiagonal[row+col] = 1;
                board[row][col] = 'Q';
                placeQueens(n,col+1,board,ans,leftRow,leftDiagonal,rightDiagonal);
                board[row][col] = '.';
                leftRow[row] = 0;
                leftDiagonal[n-1 + col-row] = 0;
                rightDiagonal[row+col] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        vector<int> leftRow(n,0);
        vector<int> leftDiagonal(2*n-1,0);
        vector<int> rightDiagonal(2*n-1,0);
        
        for(int i=0;i<n;++i)
        {
            board[i] = s;
        }
        placeQueens(n,0,board,ans,leftRow,leftDiagonal,rightDiagonal);
        return ans;
    }
};