//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int findMaxPath(int i, int j, vector<vector<int>> &matrix,vector<vector<int>> &dp)
    {
        if(j<0 || j>=matrix.size())
        return INT_MIN;
        if(i == 0)
        return matrix[i][j];
        
        if(dp[i][j] != -1)
        return dp[i][j];
        
        int leftD = findMaxPath(i-1,j-1,matrix,dp);
        int rightD = findMaxPath(i-1,j+1,matrix,dp);
        int up = findMaxPath(i-1,j,matrix,dp);
        
        return dp[i][j] = max(up,max(leftD,rightD)) + matrix[i][j];
    }
public:
    int maximumPath(int N, vector<vector<int>> &matrix)
    {
        int res = INT_MIN;
        vector<vector<int>> dp(N,vector<int>(N,-1));
        
        for(int i=0;i<N;++i)
            res = max(res,findMaxPath(N-1,i,matrix,dp));
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends