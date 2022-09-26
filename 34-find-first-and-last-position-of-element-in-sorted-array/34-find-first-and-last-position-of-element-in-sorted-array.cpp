class Solution {
public:
    int binarySearchLeft(const vector<int> &nums, int target)
    {
        int low = 0,high = nums.size()-1;
        
        while(low<=high)
        {
            int mid = (low+high)/2;
            
            if(nums[mid]>target)
                high = mid-1;
            else if(nums[mid]<target)
                low = mid+1;
            else{
                if(mid==0 || nums[mid] != nums[mid-1])
                    return mid;
                else
                    high = mid-1;
            }
        }
        return -1;
    
    }
    
    int binarySearchRight(const vector<int> &nums, int target)
    {
        int low = 0,high = nums.size()-1;
        int n = nums.size();
        while(low<=high)
        {
            int mid = (low+high)/2;
            
            if(nums[mid]>target)
                high = mid-1;
            else if(nums[mid]<target)
                low = mid+1;
            else{
                if(mid== n-1 || nums[mid] != nums[mid+1])
                    return mid;
                else
                    low = mid+1;
            }
        }
        return -1;
        
    }
    
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int> v(2);
        
        v[0] = binarySearchLeft(nums,target);
        v[1] = binarySearchRight(nums,target);
        
        return v;
    }
};