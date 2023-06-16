class Solution {
private:
    void findCount(vector<int> &nums,int index, int target, int &count)
    {
        
        if(index == nums.size())
        {
           if(target == 0) 
           {
               count++;
           }
            
            return;
        }
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