class Solution {
public:
    bool closeStrings(string word1, string word2) 
    {
        if(word1.length()!=word2.length())
            return false;
        vector<int>w1(26),w2(26),s1(26),s2(26);
        
        for(auto &c : word1)
        {
            w1[c- 'a']++;
            s1[c-'a'] = 1;
        }
        
        for(auto &c : word2)
        {
            w2[c- 'a']++;
            s2[c-'a'] = 1;
        }
        
        sort(w1.begin(),w1.end());
        sort(w2.begin(),w2.end());
        
        return w1==w2 && s1==s2;
            
        
    }
};