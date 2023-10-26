//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	private:
	int find(int arr[], int n,int index,int lastIndex,vector<vector<int>> &dp)
	{
	    if(index == n)
	        return 0;
	    if(dp[index][lastIndex+1]!= -1)
	    return dp[index][lastIndex+1];
	    int notTake = find(arr,n,index+1,lastIndex,dp);
	    int take = INT_MIN;
	    if( (lastIndex == -1) ||( arr[index] > arr[lastIndex]) )
	    take = arr[index]+ find(arr,n,index+1,index,dp);
	    
	    return dp[index][lastIndex+1] = max(take,notTake);
	}
	public:
	int maxSumIS(int nums[], int n)  
	{ 
	    vector<int> dp(n+1,0);
	    
	    for(int index=n-1;index>=0;--index)
        {
            for(int lastIndex=-1;lastIndex<index;++lastIndex)
            {
                int take = 0;
                if(lastIndex == -1 || nums[index] > nums[lastIndex])
                    take = nums[index] + dp[index+1];
                int notTake = dp[lastIndex+1];
                dp[lastIndex+1] =  max(take,notTake);                
            }
        }
        return dp[0];
	    
	    
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
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends