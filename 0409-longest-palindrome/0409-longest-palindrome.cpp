class Solution {
public:
    int longestPalindrome(string s) 
    {
        unordered_map<char,int> mp;
        int odd = 0 ,res = 0;
        
        for(auto &x : s)
            mp[x]++;
        
        for(auto &x : mp)
        {
            if(x.second & 1)
                odd++;
            res += x.second;            
        }
        return res-odd +(odd>=1);
        
    }
};