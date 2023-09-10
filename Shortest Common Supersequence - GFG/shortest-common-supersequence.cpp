//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        vector<int>curr(n+1,0),prev(n+1,0);
        
        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(X[i-1] == Y[j-1])
                curr[j] = 1+ prev[j-1];
                else
                curr[j] = max(prev[j],curr[j-1]);
            }
            prev = curr;
        }
        return m+n-curr[n];
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends