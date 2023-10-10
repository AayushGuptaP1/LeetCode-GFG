class Solution {
private:
    int findLIS(vector<int> &nums,int index, int size, int lastIndex,vector<vector<int>> &dp)
    {
        if(index == size)
            return 0;
        if(dp[index][lastIndex+1] != -1)
            return dp[index][lastIndex+1];
        int take = 0;
        if(lastIndex == -1 || nums[index] > nums[lastIndex])
            take = 1 + findLIS(nums,index+1,size,index,dp);
        int notTake = findLIS(nums,index+1,size,lastIndex,dp);
        return dp[index][lastIndex+1] =  max(take,notTake);
    }
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));        
        return findLIS(nums,0,n,-1,dp);
    }
};