class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int n = nums.size();
        int m1 = -1, m2 = -1;
        
        for(int i=0;i<n;++i)
        {
            if(nums[i] > m1)
            {
                m2 = m1;               
                m1 = nums[i];     
            }
            else
                m2 = max(m2,nums[i]);
        }
        return (m1-1)*(m2-1);
        
        
        
        
    }
};