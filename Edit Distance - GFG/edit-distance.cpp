//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int editDistance(string word1, string word2)
    {
       int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        for(int i=0;i<=m;++i)
        {
            dp[i][0] = i;
        }
        for(int j=0;j<=n;++j)
        {
            dp[0][j] = j;
        }
        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                {
                    int insert = 1+dp[i][j-1];
                    int update = 1+dp[i-1][j-1];
                    int del = 1+dp[i-1][j];
        
                    dp[i][j] =  min(insert,min(update,del));
                }
            }
        }
        return dp[m][n];
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends