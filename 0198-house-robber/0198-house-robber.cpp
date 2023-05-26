class Solution {

    // two options :either take index-2 and current index or index just before 
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        
        
        
        int prev2=0, prev = 0;
        
        for(int i=0;i<n;++i)
        {
            
            int temp = prev;
            prev = max(prev, prev2+nums[i]);
            prev2 = temp;
            
        }
        return prev;       
    }
};