//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int minimizeSum(int n, vector<vector<int>>& triangle) 
    {
        vector<int> curr(n,0);
        
        for(int i=0;i<n;++i)
        {
            curr[i] = triangle[n-1][i];
        }
        
        for(int i=n-2;i>=0;--i)
        {
            for(int j=0;j<=i;++j)
            {
                curr[j] = min(curr[j],curr[j+1]) + triangle[i][j];
            }
            
        }
        return curr[0];
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