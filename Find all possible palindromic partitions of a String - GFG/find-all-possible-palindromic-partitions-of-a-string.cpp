//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  private:
    bool isPalindrome(string s,int start, int end)
    {
        
        
        while(start<=end)
        {
            if(s[start] != s[end])
                return false;
            start++,end--;
        }
        return true;
    }
    
    void createPalindrome(string s,int index, vector<string> &path, vector<vector<string>> & ans)
    {
        if(index==s.length())
        {
            ans.push_back(path);
            return;
        }
        
        for(int i=index;i<s.length();++i)
        {
            if(isPalindrome(s,index,i))
            {
                path.push_back(s.substr(index,i-index+1));
                createPalindrome(s,i+1,path,ans);
                path.pop_back();
            }
        }
        
        
    }
  public:
    vector<vector<string>> allPalindromicPerms(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        
        createPalindrome(s,0,path,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends