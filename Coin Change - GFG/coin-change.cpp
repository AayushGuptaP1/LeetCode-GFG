//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int n, int amount) 
    {
        vector<long long int> curr(amount+1,0);
        
        for(int i=0;i<=amount;++i)
            if(i%coins[0] == 0)
                curr[i] = 1;
        
        for(int i=1;i<n;++i)
        {
            for(int j=0;j<=amount;++j)
            {
                long long int notTake = curr[j];
                long long int take = 0;
                if(j>=coins[i])
                    take = curr[j-coins[i]];
                
                curr[j] = take+notTake;
            }
        }
        
        return curr[amount];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends