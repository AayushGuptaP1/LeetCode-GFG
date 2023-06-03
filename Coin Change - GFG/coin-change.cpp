//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
  long long int findWays(int n, int index, int c[], vector<vector<long long int>> &dp)
{
    if(n<0 || index<0)
    return 0;
    
    if(dp[index][n] != -1)
    return dp[index][n];
    
    if(n==0)
    return 1;
    
    return   dp[index][n] =  findWays(n- c[index],index,c,dp)+findWays(n,index-1,c,dp);
}

  public:
    long long int count(int coins[], int size, int n)
    {
        vector<vector<long long int>> dp(size+1,vector<long long int>(n+1,-1));
        return findWays(n,size-1,coins,dp); 
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