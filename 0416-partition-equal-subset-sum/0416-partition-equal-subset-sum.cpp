class Solution {
public:
    bool canPartition(vector<int>& nums)
    {
        int n = nums.size();
        int totalSum =  accumulate(begin(nums),end(nums),0);
        
        if(totalSum %2  == 1) return false;
        totalSum /= 2;   
        
        vector<vector<bool>> dp(n,vector<bool>(totalSum +1,false));
        
        for(int i=0;i<n;++i)
            dp[i][0] = true;
        
        
        for(int i=1;i<n;++i)
        {
            for(int j=1;j<=totalSum;++j)
            {
                bool notTake = dp[i-1][j];
                bool take = (j>= nums[i]) ? dp[i-1][j-nums[i]] : false;
                dp[i][j] = notTake| take ;
            }
        }
        return dp[n-1][totalSum];
    }
};