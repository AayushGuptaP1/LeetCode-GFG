class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,1e5));
        
        for(int i=0;i<=amount;++i)
        {
            if(i%coins[0] == 0)
                dp[0][i] = i/coins[0];
        }
        
        for(int i=1;i<n;++i)
        {
            for(int j=0;j<=amount;++j)
            {
                int notTake = dp[i-1][j];
                int take = 1e5;
                if(j>=coins[i])
                    take = 1+ dp[i][j-coins[i]];
                
                dp[i][j] = min(take,notTake);
            }
        }
        int ans = dp[n-1][amount];
        
        if(ans >= 1e5)
            return -1;
        return ans;
        
    }
};