class Solution {
public:
    int arraySign(vector<int>& nums) 
    {
        int product  = 1;
        
        for(auto &x : nums)
        {
            if(x==0)
                return x;
            product *= (x/abs(x));
        }
        return product;
    }
};