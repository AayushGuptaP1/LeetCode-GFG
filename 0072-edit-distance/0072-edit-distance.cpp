class Solution {
private:
    int findDistance(string &word1, string &word2, int i,int j,vector<vector<int>> &dp)
    {
        if(i==0)
            return j;
        if(j==0)
            return i;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(word1[i-1] == word2[j-1])
            return dp[i][j] = findDistance(word1,word2,i-1,j-1,dp);
        int insert = 1+findDistance(word1,word2,i,j-1,dp);
        int update = 1+ findDistance(word1,word2,i-1,j-1,dp);
        int del = 1+ findDistance(word1,word2,i-1,j,dp);
        
        return dp[i][j] =  min(insert,min(update,del));
    }
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return findDistance(word1,word2,m,n,dp);
    }
};