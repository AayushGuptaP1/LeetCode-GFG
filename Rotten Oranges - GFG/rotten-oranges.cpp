//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int fresh = 0;
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                }
                else if(grid[i][j]==1)
                    fresh++;
            }
        }
        
        while(q.empty()==false)
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            
            q.pop();
            res = max(res,time);
            
            if(row-1>=0 && row-1<m && grid[row-1][col]==1)
            {
                q.push({{row-1,col},time+1});
                grid[row-1][col] = 0;
                fresh--;
            }
            if(row+1>=0 && row+1<m && grid[row+1][col]==1)
            {
                q.push({{row+1,col},time+1});
                grid[row+1][col] = 0;
                fresh--;
            }
            if(col-1>=0 && col-1<n && grid[row][col-1]==1)
            {
                q.push({{row,col-1},time+1});
                grid[row][col-1] = 0;
                fresh--;
            }
            if(col+1>=0 && col+1<n && grid[row][col+1]==1)
            {
                q.push({{row,col+1},time+1});
                grid[row][col+1] = 0;
                fresh--;
            }
        }
        return fresh==0? res : -1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends