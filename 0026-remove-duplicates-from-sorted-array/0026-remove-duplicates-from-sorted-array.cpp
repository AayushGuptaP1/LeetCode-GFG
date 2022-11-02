class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int i = 0, j = 1;
        int n = nums.size();
        while(j<n)
        {
            if(nums[i]==nums[j])
                j++;
            else                
                nums[++i] = nums[j++];
        }
        return i+1;
    }
};