class Solution {
public:
    int maxDepth(string s) 
    {
        int count = 0, res = 0;        
        
        for(auto &x : s)
        {
            if(x == '(')
                res = max(++count,res);               
            else if(x == ')')
                --count;            
        }
        return res;        
    }
};