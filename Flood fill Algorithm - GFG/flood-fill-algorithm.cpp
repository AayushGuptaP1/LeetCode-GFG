//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        int m = image.size();
        int n = image[0].size();
        int source = image[sr][sc];
        queue<pair<int,int>>q;
        image[sr][sc] = newColor;
        q.push({sr,sc});
        
        while(q.empty()==false)
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            if(row-1>=0 && row-1<m && image[row-1][col] == source && image[row-1][col] != newColor)
            {
                q.push({row-1,col});
                image[row-1][col] = newColor;
            }
            if(row+1>=0 && row+1<m && image[row+1][col] == source && image[row+1][col] != newColor)
            {
                q.push({row+1,col});
                image[row+1][col] = newColor;
            }
            if(col+1>=0 && col+1<n && image[row][col+1] == source && image[row][col+1] != newColor)
            {
                q.push({row,col+1});
                image[row][col+1] = newColor;
            }
            if(col-1>=0 && col-1<n && image[row][col-1] == source && image[row][col-1] != newColor)
            {
                q.push({row,col-1});
                image[row][col-1] = newColor;
            }
        }
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends