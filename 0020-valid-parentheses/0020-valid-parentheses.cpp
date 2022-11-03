class Solution {
public:
    bool isMatching(char &a, char &b)
    {
       return ((a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']'));
    }
    bool isValid(string s) 
    {
        stack<char> st;
        for(int i=0;s[i]!='\0';i++)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                st.push(s[i]);
            else
            {
                if(st.empty())
                    return false;
                else if (isMatching(st.top(), s[i]))
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();
    }
};