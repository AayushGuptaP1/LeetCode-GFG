class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int,int>mp;
        vector<int> res;
        
        for(int &c : nums1)
            mp[c]++;
        
        for(int &c : nums2)
        {
            if(mp[c]>0)
            {
                res.push_back(c);
                mp[c]--;
            }
            else
                mp.erase(c);                
        }
        return res;
        
        
    }
};