class Solution {
public:
    
    int differenceOfSum(vector<int>& nums)
    {
        int size = nums.size();
        int sum = 0;
        
        
        for(int i=0;i<size;++i)
        {
            int n = nums[i];
            sum += n;
            while(n>0)
            {
                sum -= n%10;
                n /= 10;
            }
        }
        return sum;
    }
};