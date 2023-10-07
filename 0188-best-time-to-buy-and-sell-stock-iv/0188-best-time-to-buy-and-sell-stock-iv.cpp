class Solution {
private:
    int findProfit(vector<int> &prices, int buy, int limit, int index, int size,vector<vector<vector<int>>> &dp)
    {
        if(index == size || limit == 0)
            return 0;
        if(dp[index][buy][limit] != -1)
            return dp[index][buy][limit];
        int profit = 0;
        if(buy && limit)
        {
            profit = max(-prices[index] + findProfit(prices,0,limit,index+1,size,dp),0+findProfit(prices,1,limit,index+1,size,dp));
        }
        else if(buy ==0 && limit)
        {
            profit = max(prices[index]+findProfit(prices,1,limit-1,index+1,size,dp),0+findProfit(prices,0,limit,index+1,size,dp));
        }
        return dp[index][buy][limit] =  profit;
            
        
    }
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        
        return findProfit(prices,1,k,0,n,dp);
        
    }
};