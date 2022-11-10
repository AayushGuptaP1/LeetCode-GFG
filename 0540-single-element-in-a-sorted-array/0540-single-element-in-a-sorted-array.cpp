class Solution {
public:
    int singleNonDuplicate(vector<int>& nums)
    {
        int low = 0, high =  nums.size()-1;
        
        while(low<high)
        {
            int mid = (low+high)>>1;
            if(nums[mid]!=nums[mid-1] && nums[mid] != nums[mid+1])
                return nums[mid];
            
            else if(mid%2==0)
            {
                if(nums[mid]==nums[mid-1])
                    high = mid-2;
                else
                    low = mid+2;
            }
            else
            {
                if(nums[mid]==nums[mid-1])
                    low = mid+1;
                else
                    high = mid-1;
            }
        }
        return nums[low];
    }
};