class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        // int i = 0, j = 1;
        // int n = nums.size();
        // while(j<n)
        // {
        //     if(nums[i]==nums[j])
        //         j++;
        //     else                
        //         nums[++i] = nums[j++];
        // }
        // return i+1;
        
        int i = 0;
        int n = nums.size();
        
        for(int j=1; j<n; ++j)
        {
            if(nums[i]!=nums[j])
                nums[++i] = nums[j];
        }
        return i+1;
    }
};