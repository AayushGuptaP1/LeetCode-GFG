//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<int> dp(W+1,0);
        
        for(int i=wt[0];i<=W;++i)
            dp[i] = val[0];
            
        for(int i=1;i<n;++i)
        {
            for(int j=W;j>=0;--j)
            {
                int notTake = 0+  dp[j];
                int take = INT_MIN;
                if(wt[i]<=j)
                take = val[i] + dp[j-wt[i]];
                dp[j] = max(take,notTake);
            }
        }
        return dp[W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends