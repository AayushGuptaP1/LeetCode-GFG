//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int minimizeSum(int n, vector<vector<int>>& triangle) 
    {
        vector<int> curr(n,0), prev(n,0);
        
        for(int i=0;i<n;++i)
        {
            prev[i] = triangle[n-1][i];
        }
        
        for(int i=n-2;i>=0;--i)
        {
            for(int j=i;j>=0;--j)
            {
                curr[j] = min(prev[j],prev[j+1]) + triangle[i][j];
            }
            prev = curr;
        }
        return prev[0];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends