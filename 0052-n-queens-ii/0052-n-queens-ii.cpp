class Solution {
private:
    void placeQueens(int n, int col,int &count,vector<int> &seq,vector<int> &leftRow, vector<int> &leftDiagonal, vector<int> &rightDiagonal)
    {
        
        
        if(col == n)
        {
            count++;
            return;
        }
        
        for(int row = 0;row<n;++row)
        {
            if(!leftRow[row] && !leftDiagonal[n-1+col-row] && !rightDiagonal[row+col])
            {
                leftRow[row] = leftDiagonal[n-1+col-row] = rightDiagonal[row+col] = 1; 
                seq.push_back(row);
                placeQueens(n,col+1,count,seq,leftRow,leftDiagonal,rightDiagonal);
                seq.pop_back();
                leftRow[row] = leftDiagonal[n-1+col-row] = rightDiagonal[row+col] = 0;
                
            }
        }
    }
public:
    int totalNQueens(int n) 
    {
        int res = 0;        
        vector<int> seq;
        vector<int> leftRow(n,0);
        vector<int> leftDiagonal(2*n-1,0);
        vector<int> rightDiagonal(2*n-1,0);
        placeQueens(n,0,res,seq,leftRow,leftDiagonal,rightDiagonal);
        return res;
    }
};