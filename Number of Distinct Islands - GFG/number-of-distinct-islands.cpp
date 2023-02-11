//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    void bfs(int row, int col,vector<vector<int>>& grid,vector<vector<bool>> &visited, set<vector<pair<int,int>>> &st)
    {
        int m = grid.size();
        int n = grid[0].size();
        visited[row][col] = true;
        vector<pair<int,int>> vt;
        queue<pair<int,int>>q;
        q.push({row,col});
        
        while(q.empty()==false)
        {
            int nRow = q.front().first;
            int nCol = q.front().second;
            q.pop();
            vt.push_back({nRow-row,nCol-col});
            
            if(nRow-1>=0 && nRow-1<m && visited[nRow-1][nCol]==false && grid[nRow-1][nCol]==1)
            {
                q.push({nRow-1,nCol});
                
                visited[nRow-1][nCol] = true;
            }
            if(nRow+1>=0 && nRow+1<m && visited[nRow+1][nCol]==false && grid[nRow+1][nCol]==1)
            {
                q.push({nRow+1,nCol});
                
                visited[nRow+1][nCol] = true;
            }
            if(nCol-1>=0 && nCol-1<n && visited[nRow][nCol-1]==false && grid[nRow][nCol-1]==1)
            {
                q.push({nRow,nCol-1});
                
                visited[nRow][nCol-1] = true;
            }
            if(nCol+1>=0 && nCol+1<n && visited[nRow][nCol+1]==false && grid[nRow][nCol+1]==1)
            {
                q.push({nRow,nCol+1});
                
                visited[nRow][nCol+1] = true;
            }
        }
        st.insert(vt);
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        set<vector<pair<int,int>>> st;
        vector<vector<bool>>visited(m,vector<bool>(n));
        
        
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j] == 1 && visited[i][j] == false)
                bfs(i,j,grid,visited,st);
                
            }
        }
        return st.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends