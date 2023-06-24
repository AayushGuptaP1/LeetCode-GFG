//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    bool subsetSum(int arr[], int sum, int index,vector<vector<int>> &dp)
    {
        if(sum == 0)
        return true;
        
        if(index <0 || sum <0)
        return false;
        
        if(dp[index][sum] != -1)
        return dp[index][sum];
        
        return dp[index][sum] = subsetSum(arr,sum,index-1,dp) || subsetSum(arr,sum-arr[index],index-1,dp);
    }
public:
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        
        for(int i=0;i<N;++i)
            sum += arr[i];
            
        if(sum & 1)
            return false;
        vector<vector<int>> dp(N,vector<int>(sum/2 +1,-1));
        return subsetSum(arr,sum/2,N-1,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends