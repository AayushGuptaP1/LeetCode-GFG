class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        
        unordered_map<int,int>mp;
        unordered_set<int>st;                
        
        for(auto x : arr)
            mp[x]++;
        
        for(auto y : mp)
            st.insert(y.second);
        
        return st.size()==mp.size();
        
    }
};