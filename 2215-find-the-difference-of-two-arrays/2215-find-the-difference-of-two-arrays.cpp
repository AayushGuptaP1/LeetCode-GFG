class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set<int> st1(begin(nums1),end(nums1));
        unordered_set<int> st2(begin(nums2),end(nums2));
        
        vector<vector<int>> res(2);
        
        for(auto &x : st1)
        {
            if(st2.find(x) == st2.end())
                res[0].emplace_back(x);
        }
        for(auto &x : st2)
        {
            if(st1.find(x) == st1.end())
                res[1].emplace_back(x);
        }
        return res;
    }
};