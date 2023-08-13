//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
int mod = 1000000007;
class Solution {
  public:
    int nthFibonacci(int n)
    {
        int temp1 = 0, temp2 = 1;
        int num;
        if(n == 1)
        return temp1;
        if(n == 2)
        return temp2;
        
        for(int i=2;i<=n;++i)
        {
            num = (temp1 + temp2)%mod;
            temp1 = temp2;
            temp2 = num;
        }
        return num;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends