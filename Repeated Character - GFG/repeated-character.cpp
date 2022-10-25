//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    char firstRep (string s)
    {
       int n = s.length()-1;
       char res = '#';
       vector<bool> v(26,false);
       
       for(int i = n; i >= 0; --i)
       {
           if(v[s[i]-'a'] == true)
           res = s[i];
           else
           v[s[i]-'a'] = true;
       }
       return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        char res = ob.firstRep (s);
        if (res == '#') cout << -1 << endl;
        else cout << res << endl;
    }
    return 0;
}



// } Driver Code Ends