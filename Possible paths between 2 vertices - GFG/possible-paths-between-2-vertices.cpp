//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int source, int destination) 
    {
        int ways = 0;
        if(source==destination)
        return 1;
        
        queue<int>q;
        q.push(source);
        
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto &x : adj[node])
            {
                if(x==destination)
                ways++;
                else
                
                    q.push(x);
                
            }
        }
        return ways;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}
// } Driver Code Ends