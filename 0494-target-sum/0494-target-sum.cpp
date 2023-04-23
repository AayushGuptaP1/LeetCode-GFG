class Solution {
private:
    void findCount(vector<int> &nums,int index, int target, int &count)
    {
        
        if(target == 0 && index == nums.size())
        {
            count++;
            return;
        }
        if(index == nums.size())
            return;
        
        findCount(nums,index+1,target-nums[index],count);
        findCount(nums,index+1,target+nums[index],count);
            
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int count = 0;
        
        findCount(nums,0,target,count);
        return count;
        
        
        
    }
};