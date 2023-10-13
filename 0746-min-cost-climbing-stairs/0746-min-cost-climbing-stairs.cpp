class Solution {
private:
    int findCost(vector<int> &cost, int index,vector<int> &dp)
    {
        if(index == 0 || index == 1)
            return cost[index];
        if(dp[index] != -1)
            return dp[index];
        
        int one = findCost(cost,index-1,dp);
        int two = INT_MAX;
        if(index-2>=0)
            two =  findCost(cost,index-2,dp);
        return dp[index] =  min(one,two) + cost[index];
            
    }
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n = cost.size();
        vector<int>dp(n,-1);
        return min(findCost(cost,n-1,dp),findCost(cost,n-2,dp));
    }
};