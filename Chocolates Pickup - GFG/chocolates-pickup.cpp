//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int m, int n, vector<vector<int>>& grid)
    {
        
        vector<vector<int>> prev(n,vector<int>(n,0)), curr(n,vector<int>(n,0));
        
        for(int j1=0;j1<n;++j1)
        {
            for(int j2=0;j2<n;++j2)
            {
                if(j1 == j2)
                    prev[j1][j2] = grid[m-1][j1];
                else
                    prev[j1][j2] = grid[m-1][j1] + grid[m-1][j2];
            }
        }
        
        for(int i=m-2;i>=0;--i)
        {
            for(int j1=0;j1<n;++j1)
            {
                for(int j2=0;j2<n;++j2)
                {
                    int res = INT_MIN;
                    
                    for(int dj1 = -1;dj1<=1;++dj1)
                    {
                        for(int dj2 = -1;dj2<=1;++dj2)
                        {
                            int value = 0;
                            if(j1 == j2)
                                value = grid[i][j1];
                            else
                                value = grid[i][j1] + grid[i][j2];
                            
                            if(j1+dj1>=0 && j1+dj1<n && j2+dj2>=0 && j2+dj2<n)
                                value += prev[j1+dj1][j2+dj2];
                            else
                                value += -1e8;
                            
                            res = max(res,value);                           
                                
                        }
                    }
                    curr[j1][j2] = res;
                    
                }
            }
            prev = curr;
        }
        return curr[0][n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends