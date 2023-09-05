class Solution {
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
    int longestCommonSubsequence(string text1, string text2)
    {
        int i = text1.length();
        int j = text2.length();
        vector<vector<int>> dp(i,vector<int>(j,-1));
        
        return findLCS(i-1,j-1,text1,text2,dp);
    }
};