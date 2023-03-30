//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
  void generateSubset(vector<int> &nums,int index,vector<int> &current, vector<vector<int>>&ans)
  {
      ans.push_back(current);
      
      for(int i=index;i<nums.size();++i)
      {
          if(i == index || nums[i]!=nums[i-1])
          {
              current.push_back(nums[i]);
              generateSubset(nums,i+1,current,ans);
              current.pop_back();
          }
      }
  }
  public:
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) 
    {
        sort(begin(nums),end(nums));
        vector<vector<int>> ans;
        vector<int> current;
        generateSubset(nums,0,current,ans);
        return ans;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;
        vector<vector<int>> ans = obj.printUniqueSubsets(nums);
        sort(ans.begin(), ans.end());
        //   printAns(ans);
        cout << "[ ";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            cout << "]";
        }
        cout << " ]\n";

        // cout<< "~\n";
    }

    return 0;
}

// } Driver Code Ends