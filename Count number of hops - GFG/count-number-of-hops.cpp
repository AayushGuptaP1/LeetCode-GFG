//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int MOD = 1000000007;
    //Function to count the number of ways in which frog can reach the top.
    long long findWays(int n, vector<long long> &dp)
    {
        if(n<0)
        return 0;
        if(n==0)
        return 1;
        if(dp[n] != -1)
        return dp[n];
        
        return dp[n] = (findWays(n-1,dp)+findWays(n-2,dp)+findWays(n-3,dp))%MOD;
        
    }
    long long countWays(int n)
    {
        vector<long long> dp(n+1,-1);
        return findWays(n,dp);
        
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends