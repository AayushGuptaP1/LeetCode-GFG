//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    bool dfs(int u,vector<bool> &visited,vector<int> &recSt, vector<int> adj[])
    {
        visited[u] = true;
        recSt[u] = 1;
        
        for(auto &x : adj[u])
        {
            if(visited[x]==false)
            {
                if(dfs(x,visited,recSt,adj)==false)
                return false;
            }
            else if(recSt[x]==1)
            return false;
        }
        recSt[u] = 0;
        return true;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        vector<int> res;
        vector<bool> visited(V);
        vector<int> recSt(V,0);
        
        for(int i=0;i<V;++i)
        {
            if(visited[i]==false)
            {
                dfs(i,visited,recSt,adj);
            }
        }
        for(int i=0;i<V;++i)
        {
            if(recSt[i]==0)
            res.push_back(i);
        }
        return res;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends