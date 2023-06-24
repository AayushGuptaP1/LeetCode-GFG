//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int n, int nums[])
    {
        
        int totalSum =  accumulate(nums,nums+n,0);
        
        if(totalSum %2  == 1) return false;
        totalSum /= 2;   
        
        vector<bool>prev(totalSum +1,false), curr(totalSum+1,true);
        prev[0] = true;
        
        
        for(int i=1;i<n;++i)
        {
            for(int j=1;j<=totalSum;++j)
            {
                bool notTake = prev[j];
                bool take = (j>= nums[i]) ? prev[j-nums[i]] : false;
                curr[j] = notTake| take ;
            }
            prev = curr;
        }
        return prev[totalSum];
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