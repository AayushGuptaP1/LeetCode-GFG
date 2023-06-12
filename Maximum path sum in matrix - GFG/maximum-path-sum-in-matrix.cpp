//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> &matrix)
    {
        int res = INT_MIN;
        vector<int>curr(N,0), prev(N,0);       
        
        for(int i=0;i<N;++i)
        {
            for(int j=0;j<N;++j)
            {
                int leftD = (j>0)? prev[j-1] : INT_MIN;
                int rightD = (j<N-1)? prev[j+1] : INT_MIN;
                curr[j] = max(prev[j],max(leftD,rightD)) + matrix[i][j];               
            }  
            prev = curr;
        } 
        
        for(int i=0;i<N;++i)
            res = max(res,prev[i]);
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