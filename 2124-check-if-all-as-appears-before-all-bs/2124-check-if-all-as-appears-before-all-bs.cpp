class Solution {
public:
    bool checkString(string &s) 
    {
        int n = s.length();
        
        
        for(int i=0;i<n-1;++i)
        {
            if(s[i] == 'b' && s[i+1] == 'a')               
                return false;                
        }
        return true;
    }
};