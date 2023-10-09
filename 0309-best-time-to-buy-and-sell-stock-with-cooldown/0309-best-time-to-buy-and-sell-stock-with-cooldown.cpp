class Solution {
private:
    int findProfit(vector<int> &prices, int index, int buy,int size,vector<vector<int>> &dp)
    {
        if(index >=size)
            return 0;
        if(dp[index][buy] != -1)
            return dp[index][buy];
        int profit = 0;
        if(buy)
        {
            profit = max(-prices[index]+ findProfit(prices,index+1,0,size,dp), findProfit(prices,index+1,1,size,dp));
        }
        else
        {
            profit = max(prices[index] + findProfit(prices,index+2,1,size,dp),findProfit(prices,index+1,0,size,dp));
        }
        return dp[index][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return findProfit(prices,0,1,n,dp);
    }
};