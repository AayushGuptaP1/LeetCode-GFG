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
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        
        for(int index = n-1;index>=0;--index)
        {
            for(int buy = 0;buy<=1;++buy)
            {
                for(int limit = 1;limit<=2;++limit)
                {
                    int profit = 0;
                    if(buy)
                    {
                        profit = max(-prices[index]+dp[index+1][0][limit],dp[index+1][1][limit]);
                    }
                    else
                    {
                        profit = max(prices[index]+ dp[index+1][1][limit-1],dp[index+1][0][limit]);
                    }
                    dp[index][buy][limit] = profit;
                }
            }
        }
        
        return dp[0][1][2];
    }
};