class Solution {
private:
    int canSplit(vector<int> & nums, int limit)
    {
        int n = nums.size(), partition = 1, sum = 0;
        
        for(int i=0;i<n;++i)
        {
            if(sum + nums[i] <= limit)
                sum += nums[i];
            else
            {
                partition++;
                sum = nums[i];
            }
        }
        return partition;
        
        
    }
public:
    int splitArray(vector<int>& nums, int k) 
    {
        int low = *max_element(begin(nums),end(nums));
        int high = accumulate(begin(nums),end(nums),0);
        
        while(low < high)
        {
            int mid = (low+high)>>1;
            
            if(canSplit(nums,mid) <= k)
                high = mid;
            else
                low = mid+1;
        }
        return high;        
    }
};