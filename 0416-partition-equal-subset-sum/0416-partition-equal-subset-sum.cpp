class Solution {
private:
   bool subsetSum(vector<int>& nums, int index, int sum,vector<vector<int>> &dp )
    {
       if(sum == 0)
           return true;
       if(index < 0 || sum < 0)
           return false;
       
       if(dp[index][sum] != -1)
           return dp[index][sum];
       
       return dp[index][sum] = (subsetSum(nums,index-1,sum,dp) || subsetSum(nums,index-1,sum-nums[index],dp));
    }
public:
    bool canPartition(vector<int>& nums)
    {
        int n = nums.size();
        int totalSum =  0;
        
        for(int i=0;i<n;++i)
            totalSum += nums[i];
        
        if(totalSum %2  == 1) return false;
        
        vector<vector<int>> dp(n,vector<int>(totalSum/2 +1,-1));
        return subsetSum(nums, n-1,totalSum/2,dp);
        
    }
};