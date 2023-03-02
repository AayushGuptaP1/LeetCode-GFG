//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src)
    {
        vector<vector<int>> graph(N);
        vector<bool> visited(N,false);
        
        for(auto &x : edges)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        vector<int> distance(N,-1);
        distance[src] = 0;
        queue<int> q;
        q.push(src);
        visited[src] = true;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto & x : graph[node])
            {
                if(visited[x]==false)
                {
                    distance[x] = distance[node] + 1;
                    q.push(x);
                    visited[x] = true;
                }
            }
        }
        return distance;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends