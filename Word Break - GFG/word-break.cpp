//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
private:
    bool isPossible(int index, string s, string A,unordered_set<string> &st)
    {
        if(index == A.length())
            return s.empty();
        s.push_back(A[index]);
        if(st.find(s) != st.end())
        {
            if(isPossible(index+1,"",A,st))
            return true;
        }
        return isPossible(index+1,s,A,st);
    }
public:
    int wordBreak(string A, vector<string> &B) 
    {
        unordered_set<string> st(begin(B),end(B));
        return isPossible(0,"",A,st);
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends