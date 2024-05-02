class Solution {
public:
    int findMaxK(vector<int>& nums)
    {
        unordered_set<int> st;
        int res = -1;
        
        for(auto &x : nums)
        {
            st.insert(x);
            if(st.find(-x) != st.end())                      
                res = max(res,abs(x));
        }
        return res;
        
    }
};