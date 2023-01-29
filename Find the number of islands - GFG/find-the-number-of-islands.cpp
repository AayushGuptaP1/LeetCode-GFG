//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 private:
    void bfs(int row, int col, vector<vector<bool>> &visited, vector<vector<char>> &grid)
    {
        visited[row][col] = true;
        int m = grid.size();
        int n = grid[0].size();
        
        
        queue<pair<int,int>>q;
        q.push({row,col});
        
        while(q.empty()==false)
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int delRow=-1;delRow<=1;delRow++)
            {
                for(int delCol=-1;delCol<=1;delCol++)
                {
                    int nRow = row + delRow;
                    int nCol = col + delCol;
                    
                    if(nRow>=0 && nRow<m && nCol>=0 && nCol<n && visited[nRow][nCol]==false && grid[nRow][nCol]=='1')
                    {
                        visited[nRow][nCol] = true;
                        q.push({nRow,nCol});
                    }
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        
        for(int row = 0; row<m; row++)
        {
            for(int col = 0; col<n; col++)
            {
                if(grid[row][col] == '1' && visited[row][col] == false)
                {
                    count++;
                     bfs(row,col,visited,grid);
                }
                   
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends