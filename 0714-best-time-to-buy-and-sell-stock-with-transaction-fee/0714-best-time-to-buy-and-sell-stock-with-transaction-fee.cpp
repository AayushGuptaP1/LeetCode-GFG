class Solution {
private:
    int findProfit(vector<int>& prices, int index, int buy, const int &fee, const int&n,vector<vector<int>> &dp)
    {
        if(index == n)
            return 0;
        int profit = 0;
        if(dp[index][buy] != -1)
            return dp[index][buy];
        if(buy)
        {
            profit = max(-prices[index]+ findProfit(prices,index+1,0,fee,n,dp),findProfit(prices,index+1,1,fee,n,dp));
        }
        else
        {
            profit = max(prices[index]-fee+findProfit(prices,index+1,1,fee,n,dp),findProfit(prices,index+1,0,fee,n,dp));
        }
        return dp[index][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        
        return findProfit(prices,0,1,fee,n,dp);
    }
};