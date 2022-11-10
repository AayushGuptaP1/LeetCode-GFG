class Solution {
public:
    string removeDuplicates(string s)
    {
        int n = s.length();
        stack<char> st;
        string res = "";
        
        for(int i=0;i<n;++i)
        {
            if( st.empty()==false && st.top()==s[i])
                st.pop();
            else
                st.push(s[i]);       
        }
        while(st.empty()==false)
        {
            res = st.top()+res;
            st.pop();
        }
        return res;
    }
};