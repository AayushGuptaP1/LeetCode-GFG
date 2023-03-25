//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    private:
    void dfs(int row, int col,vector<vector<char>> &grid, vector<vector<bool>> &visited)
    {
        if(row<0 || row==grid.size() || col<0 || col == grid[0].size() || visited[row][col] || grid[row][col] == 'O')
        return;
        visited[row][col] = true;
        dfs(row-1,col,grid,visited);
        dfs(row+1,col,grid,visited);
        dfs(row,col-1,grid,visited);
        dfs(row,col+1,grid,visited);
        
        
    }
    public:
    //Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) 
    {
        int shapes = 0;
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[0].size();++j)
            {
                if(grid[i][j] == 'X' && visited[i][j]==false)
                {
                    shapes++;
                    dfs(i,j,grid,visited);
                }
            }
        }
        return shapes;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends