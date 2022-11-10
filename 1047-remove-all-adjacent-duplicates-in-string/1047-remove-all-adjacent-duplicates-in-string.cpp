class Solution {
public:
    string removeDuplicates(string s)
    {
        int n = s.length();
        
        string res = "";
        
        for(int i=0;i<n;++i)
        {
            if( res.size()&& res.back()==s[i])
                res.pop_back();
            else
                res.push_back(s[i]);       
        }
        
        return res;
    }
};