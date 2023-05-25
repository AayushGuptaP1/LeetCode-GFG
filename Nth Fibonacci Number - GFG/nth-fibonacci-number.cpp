//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int nthFibonacci(long long int n)
    {
        if(n<=1)
        return n;
        long long temp1 = 0, temp2 = 1;
        long long res = 0;
        
        for(long long i = 2; i<=n; ++i)
        {
            res = temp1%1000000007 + temp2%1000000007;
            temp1 = temp2%1000000007;
            temp2 = res%1000000007;
        }
        return res%1000000007;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends