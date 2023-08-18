class Solution {
private:
    int findCount(vector<int> &nums,int index, int target)
    {
        if(index <0)
           return(target == 0);      
 
        return findCount(nums,index-1,target-nums[index]) +
        findCount(nums,index-1,target+nums[index]);
            
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int n= nums.size();
        return findCount(nums,n-1,target);
    }
};