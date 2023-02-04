//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
void dfs(int row,int col, int m, int n, vector<vector<char>> &mat)
{
    if(row<0 || row==m || col<0 || col==n || mat[row][col] != 'O')
    return;
    
    mat[row][col] = '#';
    dfs(row-1,col,m,n,mat);
    dfs(row+1,col,m,n,mat);
    dfs(row,col-1,m,n,mat);
    dfs(row,col+1,m,n,mat);
}
public:
    vector<vector<char>> fill(int m, int n, vector<vector<char>>& mat)
    {
        
        
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(i==0 || i==m-1 || j==0 || j==n-1)
                {
                    if(mat[i][j] == 'O')
                    dfs(i,j,m,n,mat);
                }
            }
        }
        
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(mat[i][j] == 'O')
                mat[i][j] = 'X';
                if(mat[i][j] == '#')
                mat[i][j] = 'O';
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends