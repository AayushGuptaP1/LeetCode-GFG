//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
private:

void dfs(int source, vector<vector<int>>& graph, vector<bool> &visited)
{
    visited[source] = true;
    
    for(auto &x : graph[source])
    {
        if(visited[x]==false)
        {
            dfs(x,graph,visited);
        }
    }
}
  public:
    int Solve(int n, vector<vector<int>>& edge) 
    {
        int edges = 0;
        int components = 0;
        vector<bool> visited(n,false);
        vector<vector<int>> graph(n);
        
        for(auto &x : edge)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
            edges++;
        }
        if(edges<n-1)
        return -1;
        
        for(int i=0;i<n;++i)
        {
            if(visited[i]==false)
            {
                components++;
                dfs(i,graph,visited);
            }
        }
        
        
        return components-1;
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends