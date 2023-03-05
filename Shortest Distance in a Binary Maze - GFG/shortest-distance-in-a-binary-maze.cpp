//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,pair<int, int> destination) 
    {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        int srcRow = source.first;
        int srcCol = source.second;
        int destRow = destination.first;
        int destCol = destination.second;
        
        int traverse[] = {-1,0,1,0,-1};
        
        if(grid[srcRow][srcCol]==0 || grid[destRow][destCol]==0)
        return -1;
        
        q.push({{srcRow,srcCol},0});
        
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            
            if(row == destRow && col == destCol)
            return time;
            
            for(int i=0;i<4;++i)
            {
                int dRow = row + traverse[i];
                int dCol = col + traverse[i+1];
                
                if(dRow>=0 && dRow<m && dCol>=0 && dCol<n && grid[dRow][dCol]==1)
                {
                    q.push({{dRow,dCol},time+1});
                    grid[dRow][dCol] = 0;
                }
            }
        }
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends