class Solution {
public:
    int minPairSum(vector<int>& nums) 
    {
        int n = nums.size(), res = INT_MIN, low = 0, high = n-1;
        sort(begin(nums),end(nums));
        
        while(low<high)
        {
            res = max(res,nums[low++]+nums[high--]);
        }
        return res;    
    }
};