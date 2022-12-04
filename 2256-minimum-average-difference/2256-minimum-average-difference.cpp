class Solution {
public:
    int minimumAverageDifference(vector<int>& nums)
    {
        long long lsum = 0;
        long long rsum = 0;
        int n = nums.size();
        int minDiff = INT_MAX;
        int res = 0;
        
        for(int i=0;i<n;++i)
            rsum += nums[i];
        
        for(int i=0;i<n;++i)
        {
            lsum += nums[i];
            rsum -= nums[i];
            
            int lavg = lsum/(i+1);
            int ravg = i==n-1 ? 0 : rsum/(n-i-1);
            
            if(abs(lavg-ravg)<minDiff)
            {
                minDiff = abs(lavg-ravg);
                res = i;
            }
                
        }
        return res;
    }
};