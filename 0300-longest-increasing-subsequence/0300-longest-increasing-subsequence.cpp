class Solution {
// private:
//     int findLIS(vector<int> &nums,int index, int size, int lastIndex,vector<vector<int>> &dp)
//     {
//         if(index == size)
//             return 0;
//         if(dp[index][lastIndex+1] != -1)
//             return dp[index][lastIndex+1];
//         int take = 0;
//         if(lastIndex == -1 || nums[index] > nums[lastIndex])
//             take = 1 + findLIS(nums,index+1,size,index,dp);
//         int notTake = findLIS(nums,index+1,size,lastIndex,dp);
//         return dp[index][lastIndex+1] =  max(take,notTake);
//     }
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0)); 
        
        for(int index=n-1;index>=0;--index)
        {
            for(int lastIndex=-1;lastIndex<index;++lastIndex)
            {
                int take = 0;
                if(lastIndex == -1 || nums[index] > nums[lastIndex])
                    take = 1 + dp[index+1][index+1];
                int notTake = dp[index+1][lastIndex+1];
                dp[index][lastIndex+1] =  max(take,notTake);                
            }
        }
        return dp[0][0];
    }
};