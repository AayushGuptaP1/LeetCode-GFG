class Solution {
public:
    bool isMatching(char &a, char &b)
    {
        return abs(a-b)==32;
    }
    string makeGood(string s) 
    {
        string res ="";
        stack<char>st;
        int n = s.length();
        
        for(int i=0;i<n;++i)
        {
            if(st.empty() || !isMatching(st.top(),s[i]))
                st.push(s[i]);
            else
                st.pop();
        }
        while(st.empty()==false)
        {
            res = st.top()+res;
            st.pop();
        }
        return res;        
    }
};