//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
  void dfs(int row,int col, int m, int n, vector<vector<int>> &grid)
  {
      if(row<0 || row==m || col<0 || col == n ||grid[row][col] != 1)
      return;
      
      grid[row][col] = -1;
      
      dfs(row-1,col,m,n,grid);
      dfs(row+1,col,m,n,grid);
      dfs(row,col-1,m,n,grid);
      dfs(row,col+1,m,n,grid);
  }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid)
    {
        int count = 0;
        
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(i==0 || i==m-1 || j==0 || j==n-1)
                {
                    if(grid[i][j]==1)
                    dfs(i,j,m,n,grid);
                }
            }
        }
        
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j] == 1)
                count++;
                if(grid[i][j] == -1)
                grid[i][j] = 1;
            }
        }
        return count;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends