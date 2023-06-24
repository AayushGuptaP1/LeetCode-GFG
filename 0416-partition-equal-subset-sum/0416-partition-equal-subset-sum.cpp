class Solution {
public:
    bool canPartition(vector<int>& nums)
    {
        int n = nums.size();
        int totalSum =  accumulate(begin(nums),end(nums),0);
        
        if(totalSum %2  == 1) return false;
        totalSum /= 2;   
        
        vector<bool>prev(totalSum +1,false), curr(totalSum+1,true);
        prev[0] = true;
        
        
        for(int i=1;i<n;++i)
        {
            for(int j=1;j<=totalSum;++j)
            {
                bool notTake = prev[j];
                bool take = (j>= nums[i]) ? prev[j-nums[i]] : false;
                curr[j] = notTake| take ;
            }
            prev = curr;
        }
        return prev[totalSum];
    }
};