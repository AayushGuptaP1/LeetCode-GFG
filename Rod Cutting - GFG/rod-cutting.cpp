//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  private:
  int findPrice(int price[], int length, int index,vector<vector<int>> &dp)
  {
      
      if(index == 0)
      return price[length-1];
      
      if(dp[length][index]!= -1)
      return dp[length][index];
      
      int noCut = findPrice(price,length,index-1,dp);
      int cut =  INT_MIN;
      if(length-index>=1)
      cut =  price[length-index-1] + findPrice(price,index,index-1,dp);
      return dp[length][index] = max(cut,noCut);
      
  }
  public:
    int cutRod(int price[], int n)
    {
        vector<vector<int>> dp(n+1,vector<int>(n,-1));
        return findPrice(price,n,n-1,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends