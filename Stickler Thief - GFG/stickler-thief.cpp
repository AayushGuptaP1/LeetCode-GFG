//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    private:
    int maxRob(int nums[], int index,vector<int> &dp)
    {
        if(index < 0)
            return 0;
        if(dp[index] != -1)
            return dp[index];
        
        return dp[index] =  max(maxRob(nums,index-2,dp)+nums[index],maxRob(nums,index-1,dp));
    }
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int nums[], int n)
    {
         vector<int> dp(n+1, -1);
        int index = n-1;
        return maxRob(nums,index,dp);
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends