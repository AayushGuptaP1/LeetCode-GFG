class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int n = nums.size();
        
        sort(begin(nums),end(nums));
        return (nums[n-1]-1)*(nums[n-2]-1);
        
        
    }
};