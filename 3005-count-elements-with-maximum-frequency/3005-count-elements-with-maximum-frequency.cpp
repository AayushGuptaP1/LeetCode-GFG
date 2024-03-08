class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) 
    {
        unordered_map<int,int> mp;
        int count = 0;
        int maxi = 0;
        
        for(auto &x : nums)
        {
            mp[x]++;
            if(mp[x] == maxi)            
                count++;
            else if(mp[x] > maxi)
            {
                count = 1;
                maxi = mp[x];
            }
            
        }
        return count*maxi;
    }
};