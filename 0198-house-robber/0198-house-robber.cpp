class Solution {

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