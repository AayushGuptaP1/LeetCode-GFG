class Solution {
private:
    int findPalindrome(string &s,string &r, int i, int j,vector<vector<int>> &dp)
    {
        if(i<0 || j<0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s[i] == r[j])
            return dp[i][j] =  1+ findPalindrome(s,r,i-1,j-1,dp);
        return dp[i][j] =  max(findPalindrome(s,r,i-1,j,dp),findPalindrome(s,r,i,j-1,dp));
    }
public:
    int longestPalindromeSubseq(string s) 
    {
        string r = s;
        reverse(begin(r),end(r));
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return findPalindrome(s,r,n-1,n-1,dp);
    }
};