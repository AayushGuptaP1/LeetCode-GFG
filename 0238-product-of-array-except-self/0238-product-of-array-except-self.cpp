class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> res(n,1);
        int postProd = 1;
      
        
        for(int i=1; i<n; ++i)
        {
            res[i] = nums[i-1]*res[i-1];
        }
        for(int i = n-2;i>=0;--i)
        {
             postProd *= nums[i+1];
            res[i] *= postProd;
           
        }
        return res;
    }
};