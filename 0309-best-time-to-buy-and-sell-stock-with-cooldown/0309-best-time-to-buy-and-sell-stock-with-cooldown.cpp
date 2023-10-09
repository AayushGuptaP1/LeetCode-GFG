class Solution {

public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        
        for(int index=n-1;index>=0;--index)
        {
            
            dp[index][1] = max(-prices[index]+ dp[index+1][0], dp[index+1][1]);
            dp[index][0] = max(prices[index] + dp[index+2][1],dp[index+1][0]);
        }              
        return dp[0][1];
    }
};