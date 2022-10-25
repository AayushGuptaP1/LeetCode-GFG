class Solution {
public:
    bool checkString(string &s) 
    {
        int n = s.length();
        bool flag = false;
        
        for(int i=0;i<n;++i)
        {
            if(s[i] == 'b')
                flag = true;
            if(flag && s[i] == 'a')
                return false;                
        }
        return true;
    }
};