class Solution {
public:
    int rob(vector<int>& nums) 
    {
        
        int res1 =0, res2= 0, prev1 = 0, prev2 = 0;
        int n = nums.size();
        if(n == 1)
            return nums[0];
        
        for(int i=0;i<n-1;++i)
        {
            res1 = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = res1;
        }
        prev1 = 0, prev2 = 0;
        for(int i=1;i<n;++i)
        {
            res2 = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = res2;
        }
        return max(res1,res2);
    }
};