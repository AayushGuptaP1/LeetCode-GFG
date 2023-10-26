//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{

  public:
    int minimumNumberOfDeletions(string s) 
    { 
        int n = s.length();
        string r = s;
        reverse(begin(r),end(r));
        vector<int>curr(n+1,0),prev(n+1,0);
      
      for(int i=1;i<=n;++i)
      {
          for(int j=1;j<=n;++j)
          {
              if(s[i-1] == r[j-1])
              curr[j] = 1 + prev[j-1];
              else
              curr[j] = max(curr[j-1],prev[j]);
          }
          prev = curr;
      }
        
        return n- curr[n];
    } 
};


//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends