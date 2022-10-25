//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string &s) 
    { 
        int n = s.size();
        int start = 0;
        
        for(int end=0;end<n;++end)
        {
            if(s[end] == '.')
            {
                reverse(s.begin()+start, s.begin()+end);
                start = end +1;
            }
        }
        reverse(s.begin()+start,s.end());
        reverse(s.begin(),s.end());
        return s; 
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends