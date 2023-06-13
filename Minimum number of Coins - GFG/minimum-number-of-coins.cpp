//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{

public:
    vector<int> minPartition(int n)
    {
        vector<int> coins =  { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        vector<int> res;
        int index = 9;
        
        while(n != 0)
        {
            if(n >= coins[index])
            {
                n -= coins[index];
                res.push_back(coins[index]);
            }
            else
            index--;
            
        }
        return res;
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends