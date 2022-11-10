class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        int n = nums.size();
        unordered_map<int,int> mp;
        int ans = 0;
        int sum = 0;
        mp[sum]++;
        
        for(int i=0;i<n;++i)
        {
            sum += nums[i];
            
            if(mp.find(sum-k) != mp.end())
                ans += mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};