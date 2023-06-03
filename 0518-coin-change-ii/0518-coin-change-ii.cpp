class Solution {
private:
int findWays(int n, int index, vector<int> &coins, vector<vector<int>> &dp)
{
    if(n<0 || index<0)
    return 0;
    
    if(dp[index][n] != -1)
    return dp[index][n];
    
    if(n==0)
    return 1;
    
    return   dp[index][n] =  findWays(n- coins[index],index,coins,dp)+findWays(n,index-1,coins,dp);
}
public:
    int change(int amount, vector<int>& coins) 
    {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        return findWays(amount,coins.size()-1,coins,dp);
    }
};