class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        int n = coins.size();
        vector<int> curr(amount+1,0);
        
        for(int i=0;i<=amount;++i)
            if(i%coins[0] == 0)
                curr[i] = 1;
        
        for(int i=1;i<n;++i)
        {
            for(int j=0;j<=amount;++j)
            {
                int notTake = curr[j];
                int take = 0;
                if(j>=coins[i])
                    take = curr[j-coins[i]];
                
                curr[j] = take+notTake;
            }
        }
        
        return curr[amount];
    }
};