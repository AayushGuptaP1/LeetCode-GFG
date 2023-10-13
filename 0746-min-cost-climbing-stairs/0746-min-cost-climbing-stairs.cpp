class Solution {
private:
    int findCost(vector<int> &cost, int index,int size,vector<int> &dp)
    {
        if(index ==size)
            return 0;
        if(dp[index] != -1)
            return dp[index];
        
        int one = findCost(cost,index+1,size,dp);
        int two = INT_MAX;
        if(index+2<=size)
            two =  findCost(cost,index+2,size,dp);
        return dp[index] =  min(one,two) + cost[index];
            
    }
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n = cost.size();
        vector<int>dp(n,-1);
        return min(findCost(cost,0,n,dp),findCost(cost,1,n,dp));
    }
};