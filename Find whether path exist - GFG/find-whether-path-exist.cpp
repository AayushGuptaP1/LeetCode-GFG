//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        queue<pair<int,int>>q;
        
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                    break;
                }
            }
        }
        
        while(q.empty()==false)
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            if(grid[row][col]==2)
            return true;
            
            if(row-1>=0 && row-1<m && grid[row-1][col]!=0 && visited[row-1][col]==false)
            {
                q.push({row-1,col});
                visited[row-1][col] = true;
            }
            if(row+1>=0 && row+1<m && grid[row+1][col]!=0 && visited[row+1][col]==false)
            {
                q.push({row+1,col});
                visited[row+1][col] = true;
            }
            if(col-1>=0 && col-1<n && grid[row][col-1]!=0 && visited[row][col-1]==false)
            {
                q.push({row,col-1});
                visited[row][col-1] = true;
            }
            if(col+1>=0 && col+1<n && grid[row][col+1]!=0 && visited[row][col+1]==false)
            {
                q.push({row,col+1});
                visited[row][col+1] = true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends