class Solution {
public:
    int sumOfSquares(vector<int>& nums)
    {
        int res = 0, n = nums.size();
        
        for(int i=0;i<n;++i)
        {
            res += (n%(i+1) == 0)? nums[i]*nums[i] : 0;
        }
        return res;        
    }
};