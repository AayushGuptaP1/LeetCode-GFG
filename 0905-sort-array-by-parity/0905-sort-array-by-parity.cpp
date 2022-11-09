class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums)
    {
        int n = nums.size();
        int i=0, j = n-1;
        
        while(i<j)
        {
            while(nums[i]%2==0 && i<j)
                i++;
            while(nums[j]%2==1 && i<j)
                j--;
            swap(nums[i++],nums[j--]);
        }
        return nums;
    }
};