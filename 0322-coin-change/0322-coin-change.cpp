class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        int n = coins.size();
        vector<int>curr(amount+1,1e5);
        
        for(int i=0;i<=amount;++i)
        {
            if(i%coins[0] == 0)
                curr[i] = i/coins[0];
        }
        
        for(int i=1;i<n;++i)
        {
            for(int j=0;j<=amount;++j)
            {
                int notTake = curr[j];
                int take = 1e5;
                if(j>=coins[i])
                    take = 1+curr[j-coins[i]];
                
                curr[j] = min(take,notTake);
            }
        }
        int ans = curr[amount];
        
        if(ans >= 1e5)
            return -1;
        return ans;
        
    }
};