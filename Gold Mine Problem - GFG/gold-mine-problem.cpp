//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
int findGold(int row, int col, vector<vector<int>> &M,vector<vector<int>> &dp)
{
    if(row <0 || row == M.size())
    return INT_MIN;
    
    if(col == 0)
    return M[row][0];
    
    if(dp[row][col] != -1)
    return dp[row][col];
    
    return dp[row][col] = M[row][col] + max(findGold(row-1,col-1,M,dp),max(findGold(row+1,col-1,M,dp),findGold(row,col-1,M,dp)));
}
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int res = 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;++i)
        {
            res = max(res, findGold(i,m-1,M,dp));
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends