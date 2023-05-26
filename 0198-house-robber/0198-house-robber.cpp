class Solution {

    // two options :either take index-2 and current index or index just before 
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        
        dp[0] = nums[0];
        int prev=0, prev2 = 0;
        
        for(int i=1;i<n;++i)
        {
            prev = dp[i-1];
            
            if(i-2>=0)
                prev2 = dp[i-2];
            dp[i] = max(prev2 + nums[i], prev);
        }
        return dp[n-1];       
    }
};