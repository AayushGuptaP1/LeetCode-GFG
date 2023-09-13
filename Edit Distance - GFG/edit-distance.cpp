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
        vector<int> prev(n+1,0),curr(n+1,0);
        
        
        for(int j=0;j<=n;++j)
        {
            prev[j] = j;
        }
        for(int i=1;i<=m;++i)
        {
            curr[0] = i;
            for(int j=1;j<=n;++j)
            {
                if(word1[i-1] == word2[j-1])
                    curr[j] = prev[j-1];
                else
                {
                    int insert = 1+curr[j-1];
                    int update = 1+prev[j-1];
                    int del = 1+prev[j];
        
                    curr[j] =  min(insert,min(update,del));
                }
            }
            prev = curr;
        }
        return curr[n];
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