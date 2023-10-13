class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n = cost.size();
        vector<int>dp(n+1,INT_MAX);
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for(int index=2;index<n;++index)
        {
            int one = dp[index-1];
            int two = INT_MAX;
            if(index-2>=0)
                two =  dp[index-2];
            dp[index] =  min(one,two) + cost[index];            
        }
        
        
        return min(dp[n-1],dp[n-2]);
    }
};