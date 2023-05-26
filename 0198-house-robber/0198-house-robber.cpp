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
        int n = nums.size();
        vector<int> dp(n+1, -1);
        
        dp[0] = nums[0];
        
        for(int i=1;i<n;++i)
        {
            int even = dp[i-1];
            int odd = 0;
            if(i-2>=0)
                odd = dp[i-2];
            dp[i] = max(odd + nums[i], even);
        }
        return dp[n-1];       
    }
};