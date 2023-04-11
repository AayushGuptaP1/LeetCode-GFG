class Solution {
public:
    string removeStars(string s) 
    {
        string res = "";
        int size = s.length();
        
        for(int i=0;i<size;++i)
        {
            if(s[i] != '*')
                res.push_back(s[i]);
            else if(!res.empty())
                res.pop_back();
        }
        return res;
    }
};