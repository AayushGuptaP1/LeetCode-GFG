class Solution {

public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        int n = prices.size();
        int buy = 0, sell = 0;
        
        for(int index = n-1;index>=0;index--)
        {
            buy = max(-prices[index]+ sell,buy);
            sell =  max(prices[index]-fee+buy,sell);
        }
        
        return buy;
    }
};