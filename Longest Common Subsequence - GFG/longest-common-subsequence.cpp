//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    private:
    int findLCS(int i, int j, string &text1, string &text2,vector<vector<int>> &dp)
    {
        if(i <0 || j<0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(text1[i] == text2[j])
            return dp[i][j]  = 1+ findLCS(i-1,j-1,text1,text2,dp);
        
        return dp[i][j] = max(findLCS(i-1,j,text1,text2,dp),findLCS(i,j-1,text1,text2,dp));
    }
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int i, int j, string text1, string text2)
    {
        vector<vector<int>> dp(i,vector<int>(j,-1));
        
        return findLCS(i-1,j-1,text1,text2,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends