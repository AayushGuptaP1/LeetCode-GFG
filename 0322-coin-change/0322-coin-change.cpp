class Solution {
private:
    int findMinCoins(vector<int> &coins, int amount, int index,vector<vector<int>> &dp)
    {
        if(index == 0)
        {
            if(amount%coins[0] == 0)
                return amount/coins[0];
            return 1e5;
        }
        if(dp[index][amount] != -1)
            return dp[index][amount];
        
        int notTake = findMinCoins(coins,amount,index-1,dp);
        int take = 1e5;
        
        if(amount>= coins[index])
            take = 1+ findMinCoins(coins,amount-coins[index],index,dp);
        
        return dp[index][amount] = min(take,notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = findMinCoins(coins,amount,n-1,dp);
        
        if(ans >= 1e5)
            return -1;
        return ans;
        
    }
};