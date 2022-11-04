//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool valid(string str);
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        cout<<valid(str)<<endl;
    }
    return 0;
}
// } Driver Code Ends

bool isMatching(char a, char b)
{
    return ((a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']'));
}
bool valid(string s)
{
    stack<char>st;
    int n = s.length();
    
    for(int i =0 ; i<n;i++)
    {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            st.push(s[i]);
        else
        {
            if (st.empty())
            return false;
            else if(!isMatching(st.top(), s[i]))
            return false;
            else
            st.pop(); 
        }
    }
    return st.empty();
}