//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n) 
	{ 
	    int totalSum = accumulate(arr,arr+n,0);
	    vector<vector<int>> dp(n,vector<int>(totalSum+1,0));
	    
	    for(int i=0;i<n;++i)
	        dp[i][0] = 1;
	    dp[0][arr[0]] = 1;
	   
	    for(int i=1;i<n;++i)
	    {
	        for(int j=1;j<=totalSum;++j)
	        {
	            int notTake = dp[i-1][j];
	            int take = 0;
	            if(j>=arr[i])
	            take = dp[i-1][j-arr[i]];
	            
	            dp[i][j] = take | notTake;
	        }
	    }
	    
	    int res = INT_MAX;
	    for(int i=0;i<=totalSum/2;++i)
	    {
	        if(dp[n-1][i] == 1)
	        {
	            res = min(res,abs(totalSum-2*i));
	        }
	    }
	    return res;
	        
	   
	    
	    
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends