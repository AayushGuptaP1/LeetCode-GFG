class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> st;
        int n = nums.size();
        
        for(int i=0;i<n;++i)
            st.insert(nums[i]);
        int res = 0;
        
        for(int i=0;i<n;++i)
        {
            if(st.find(nums[i]-1) == st.end())
            {
                int curr =1;
                while(st.find(nums[i]+curr) != st.end())
                    curr++;
                res = max(res,curr);
            }
        }
        return res;
        
    }
};