//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    int bfs(int i, int j,vector<vector<int>>& grid,vector<vector<bool>> &visited)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int,int>>q;
        q.push({i,j});
        int res = 0;
        
        while(q.empty()==false)
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            
            
            for(int delRow=row-1;delRow<=row+1;delRow++)
            {
                for(int delCol=col-1;delCol<=col+1;delCol++)
                {
                    if(delRow>=0 && delRow<m && delCol>=0 && delCol<n && visited[delRow][delCol]==false && grid[delRow][delCol]==1)
                    {
                        q.push({delRow,delCol});
                        res++;
                        visited[delRow][delCol]= true;
                    }
                }
            }
        }
        return res;
    }
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int maxArea = 0;
        
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(visited[i][j]==false && grid[i][j]==1)
                {
                    maxArea = max(maxArea,bfs(i,j,grid,visited));
                }
                
            }
        }
        return maxArea;
        
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
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends