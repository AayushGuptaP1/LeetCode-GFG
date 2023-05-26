class Solution {
private:
    int maxRob(vector<int> &nums, int index,vector<int> &dp)
    {
        if(index < 0)
            return 0;
        if(dp[index] != -1)
            return dp[index];
        
        return dp[index] =  max(maxRob(nums,index-2,dp)+nums[index],maxRob(nums,index-1,dp));
    }
public:
    int rob(vector<int>& nums) 
    {
        vector<int> dp(nums.size()+1, -1);
        int index = nums.size()-1;
        return maxRob(nums,index,dp);        
    }
};