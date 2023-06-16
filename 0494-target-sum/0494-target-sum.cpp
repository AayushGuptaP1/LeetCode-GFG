class Solution {
private:
    int findCount(vector<int> &nums,int index, int target)
    {
        if(index == nums.size())
        {
            if(target == 0)
                return 1;
            return 0;
        }             
        return findCount(nums,index+1,target-nums[index])+
        findCount(nums,index+1,target+nums[index]);
            
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {        
        return findCount(nums,0,target);      
    }
};