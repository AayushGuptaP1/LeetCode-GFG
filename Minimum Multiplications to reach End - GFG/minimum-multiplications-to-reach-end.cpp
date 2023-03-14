//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end)
    {
        vector<int> minMult(100001,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,start});
        
        while(!pq.empty())
        {
            int mult = pq.top().first;
            int num = pq.top().second;
            pq.pop();
            
            if(num==end)
            return mult;
            
            for(auto &x : arr)
            {
                int temp = (num*x)%100000;
                
                
                if(mult+1 < minMult[temp])
                {
                    minMult[temp] = mult+1;
                    pq.push({minMult[temp],temp});
                }
            }
        }
        return -1;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends