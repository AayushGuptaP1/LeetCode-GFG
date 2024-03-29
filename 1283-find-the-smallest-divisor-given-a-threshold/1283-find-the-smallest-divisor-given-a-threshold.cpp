class Solution {
private:
    bool isPossible(const int& mid, vector<int>& nums, const int& threshold)
    {
        int res = 0;
        for(const int &x : nums)
        {
            res += x/mid + (x%mid != 0);
        }
        return res<= threshold;
    }
public:
    int smallestDivisor(vector<int>& nums, const int& threshold) 
    {
        int low = 1, high = *max_element(begin(nums),end(nums)), mid;
        
        while(low < high)
        {
            mid = (low+high)>>1;
            
            if(isPossible(mid,nums,threshold))
                high = mid;
            else
                low = mid+1;
        }
        return high;
    }
};