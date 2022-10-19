class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
       unordered_map <int,int> mp;
        
        int n = nums.size();
        
        for(int i=0;i<n;++i)
        {
            if(mp.find(target-nums[i]) == mp.end())
                mp.insert({nums[i],i});
            else
                return {i,mp[target-nums[i]]};
        }
        return {};
    }
};