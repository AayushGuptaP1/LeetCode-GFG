//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
private:
void findCombinations(vector<int> &arr,int index,int target,vector<int> &current,vector<vector<int>> &ans)
{
    if(target<0)
    return;
    else if(target == 0)
    {
        ans.push_back(current);
        return;
    }
    
    for(int i=index;i<arr.size();++i)
    {
        if(i== index || arr[i]!=arr[i-1])
        {
            current.push_back(arr[i]);
            findCombinations(arr,i+1,target-arr[i],current,ans);
            current.pop_back();
        }
    }
}
public:
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        sort(begin(arr),end(arr));
        vector<int> current;
        vector<vector<int>> ans;
        findCombinations(arr,0,k,current,ans);
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends