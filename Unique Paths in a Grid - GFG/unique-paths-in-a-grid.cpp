//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int uniquePaths(int m, int n, vector<vector<int>> &obstacleGrid) 
    {
        int mod = 1e9+7;
        vector<int>dp(n,0);
        dp[0] = 1;            
        
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(obstacleGrid[i][j] == 0)
                    dp[j] = 0;              
                else if(j>0)
                {
                    dp[j] += (dp[j-1]);
                    dp[j]%=mod;
                }
                    
            }
        }
        return (dp[n-1]);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends