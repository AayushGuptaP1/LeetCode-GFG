//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
void placeQueens(int n, int col,vector<int> &seq, vector<vector<int>> &ans, vector<int> &leftRow, vector<int> &leftDiagonal, vector<int> &rightDiagonal)
{
    if(seq.size() == n)
    {
        ans.push_back(seq);
        return;
    }
    
    for(int row = 0;row<n;++row)
    {
        if(leftRow[row] == 0 && leftDiagonal[n-1+col-row] == 0 && rightDiagonal[row+col] == 0)
        {
            leftRow[row] = leftDiagonal[n-1+col-row] = rightDiagonal[row+col] = 1;
            seq.push_back(row+1);
            placeQueens(n,col+1,seq,ans,leftRow,leftDiagonal,rightDiagonal);
            leftRow[row] = leftDiagonal[n-1+col-row] = rightDiagonal[row+col] = 0;
            seq.pop_back();
            
        }
    }
}
public:
    vector<vector<int>> nQueen(int n) 
    {
        vector<vector<int>> ans;
        vector<int> seq;
        vector<int>leftRow(n,0);
        vector<int>leftDiagonal(2*n-1,0);
        vector<int>rightDiagonal(2*n-1,0);
        placeQueens(n,0,seq,ans,leftRow,leftDiagonal,rightDiagonal);
        return ans;
        
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends