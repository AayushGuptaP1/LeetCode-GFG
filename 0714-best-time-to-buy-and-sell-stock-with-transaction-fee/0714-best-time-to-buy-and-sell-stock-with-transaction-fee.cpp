class Solution {

public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        int n = prices.size();
        vector<int> curr(2,0);
        
        for(int index = n-1;index>=0;index--)
        {
            curr[1] = max(-prices[index]+ curr[0],curr[1]);
            curr[0] =  max(prices[index]-fee+curr[1],curr[0]);
        }
        
        return curr[1];
    }
};