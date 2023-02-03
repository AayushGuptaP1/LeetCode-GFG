//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int m = grid.size();
	    int n = grid[0].size();
	    
	    vector<vector<int>>result(m,vector<int>(n));
	    queue<pair<int,int>>q;
	    
	    for(int i=0;i<m;++i)
	    {
	        for(int j=0;j<n;++j)
	        {
	            if(grid[i][j]==1)
	                q.push({i,j});
	            else
	            result[i][j] = -1;
	        }
	    }
	    
	    while(q.empty()==false)
	    {
	        int row = q.front().first;
	        int col = q.front().second;
	        q.pop();
	        
	        if(row-1>=0 && row-1<m && result[row-1][col]== -1)
	        {
	            result[row-1][col] = result[row][col]+1;
	            q.push({row-1,col});
	        }
	        if(row+1>=0 && row+1<m && result[row+1][col]== -1)
	        {
	            result[row+1][col] = result[row][col]+1;
	            q.push({row+1,col});
	        }
	        if(col-1>=0 && col-1<n && result[row][col-1]== -1)
	        {
	            result[row][col-1] = result[row][col]+1;
	            q.push({row,col-1});
	        }
	        if(col+1>=0 && col+1<n && result[row][col+1]== -1)
	        {
	            result[row][col+1] = result[row][col]+1;
	            q.push({row,col+1});
	        }
	    }
	    return result;
	    
	    
	    
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends