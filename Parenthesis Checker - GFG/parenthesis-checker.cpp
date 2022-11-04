//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    


    public:
    //Function to check if brackets are balanced or not.
bool isMatching(char &a, char &b)
{
    return ((a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']'));
}
string isBalanced(string s) 
{
    
    }
    bool ispar(string x)
    {
        stack<char> st;
    for(int i=0;i<x.length();i++)
    {
        if(x[i]=='(' || x[i]=='{' || x[i]== '[')
            st.push(x[i]);
        else
        {
            if (st.empty())
            return false;
            else if(!isMatching(st.top(), x[i]))
            return false;
            else
            st.pop();              
        }        
    }
    return st.empty();
    }



};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends