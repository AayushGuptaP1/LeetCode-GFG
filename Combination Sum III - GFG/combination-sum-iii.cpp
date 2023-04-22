//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
 void generateSum(int sum,int index,int k,int n,vector<int> &seq, vector<vector<int>> &res)
    {
        if(sum>n || k<0)
            return;
        if(sum == n && k== 0)
        {
            res.push_back(seq);
            return;
        }
        for(int i=index;i<=9;++i)
        {
            seq.push_back(i);
            generateSum(sum+i,i+1,k-1,n,seq,res);
            seq.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(int k, int n)
    {
        vector<vector<int>> res;
        vector<int> seq;
        
        
        generateSum(0,1,k,n,seq,res);
        return res;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends