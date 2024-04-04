class Solution {
public:
    int maxDepth(string s) 
    {
        int count = 0;
        int res = 0;
        
        for(auto &x : s)
        {
            if(x == '(')
                count++;
            else if(x == ')')
                count--;
            res = max(res,count);
        }
        return res;
        
    }
};