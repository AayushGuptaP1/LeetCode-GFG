class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp.insert({0,-1});
        int sum = 0;
        int res = 0;
        
        for(int i=0;i<n;++i)
        {
            sum += nums[i]?1:-1;
            if(mp.find(sum) == mp.end())
                mp.insert({sum,i});
            else
                res = max(res,i-mp[sum]);                
        }
        return res;
    }
};