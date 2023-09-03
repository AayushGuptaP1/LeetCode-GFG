class Solution {
private:
int findWays(int index, vector<int> &coins,int amount,vector<vector<int>> &dp)
{
    if(index == 0)
        return (amount%coins[0] == 0);
    
    if(dp[index][amount] != -1)
        return dp[index][amount];    
    
    int notTake = findWays(index-1,coins,amount,dp);
    int take = 0;
    if(amount>= coins[index])
        take = findWays(index,coins,amount-coins[index],dp);
    
    return dp[index][amount] = take+notTake;
}
public:
    int change(int amount, vector<int>& coins) 
    {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        
        return findWays(n-1,coins,amount,dp);
    }
};