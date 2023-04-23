//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
 private:
    void findCount(vector<int> &nums,int index, int target, int &count)
    {
        
        if(target == 0 && index == nums.size())
        {
            count++;
            return;
        }
        if(index == nums.size())
            return;
        
        findCount(nums,index+1,target-nums[index],count);
        findCount(nums,index+1,target+nums[index],count);
            
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int count = 0;
        
        findCount(nums,0,target,count);
        return count;
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends