class Solution {
private:
    int findMinJumps(int index, vector<int> &nums, int size,vector<int> &dp)
    {
        if(index > size)
            return INT_MAX-1;
        if(index == size)
            return 0;
        if(dp[index] != -1)
            return dp[index];
        
        int res = INT_MAX-1;
        
        for(int i=1; i<=nums[index];++i)
        {
            res = min(res,1+findMinJumps(index+i,nums,size,dp));
        }
        return dp[index] = res ;
    }
public:
    int jump(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n,-1);
        return findMinJumps(0,nums,n-1,dp);
        
    }
};