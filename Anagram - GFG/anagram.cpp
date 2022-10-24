//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string &s, string &t)
    {
        
        if(s.length() != t.length())
            return false;
        
        int n = s.length();        
        int count[26]={0};
        
        for(int i = 0; i<n;++i)
        {
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }
        
        for(int i=0;i<26;++i)
        {
            if(count[i])
                return false;
        }
        return true;
        
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends