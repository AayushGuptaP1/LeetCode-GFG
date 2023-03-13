//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads)
    {
        vector<long long> ways(n,0);
        vector<long long> distance(n,LONG_MAX);
        distance[0] = 0;
        ways[0] = 1;
        vector<vector<pair<int,int>>> graph(n);
        
        for(auto &x : roads)
        {
            graph[x[0]].push_back({x[1],x[2]});
            graph[x[1]].push_back({x[0],x[2]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        
        while(!pq.empty())
        {
            long long dist = pq.top().first;
            long long node = pq.top().second;
            pq.pop();
            
            for(auto &x : graph[node])
            {
                int adjNode = x.first;
                int edWt = x.second;
                
                if(dist + edWt < distance[adjNode])
                {
                    distance[adjNode] = dist + edWt;
                    pq.push({distance[adjNode],adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(dist + edWt == distance[adjNode])
                {
                    ways[adjNode] = (ways[adjNode] + ways[node])%100000007;
                    
                }
            }
        }
        return ways[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends