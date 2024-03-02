class Solution {
public:
    string maximumOddBinaryNumber(string s) 
    {
        int one = 0, zero = 0;
        string res = "";
        
        for(int i=0;i<s.length();++i)
        {
            if(s[i] == '1')
                one++;
            else
                zero++;
        }
        for(int i=0;i<one-1;++i)
            res.push_back('1');
        
        for(int i=0;i<zero;++i)
            res.push_back('0');
        res.push_back('1');
        
        return res;
            
    }
};