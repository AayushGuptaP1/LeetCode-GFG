//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  private:
  void topSort(int node, vector<vector<pair<int,int>>> &graph, vector<bool> &visited,stack<int> &st)
  {
      visited[node] = true;
      
      for(auto &x : graph[node])
      {
          int v = x.first;
          if(visited[v]==false)
          topSort(v,graph,visited,st);
      }
      st.push(node);
  }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges)
     {
        vector<int>distance(N,INT_MAX);
        vector<bool> visited(N,false);
        distance[0] = 0;
        vector<vector<pair<int,int>>> graph(N);
        
        for(int i=0;i<M;++i)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            graph[u].push_back({v,wt});
        }
        
        //topSort
        stack<int> st;
        for(int i=0;i<N;++i)
        {
            if(visited[i]==false)
            topSort(i,graph,visited,st);
        }
        
        while(st.empty()==false)
        {
            int u = st.top();
            st.pop();
            
            for(auto &x : graph[u])
            {
                int v = x.first;
                int wt = x.second;
                
                if(distance[u]!= INT_MAX)
                distance[v] = min(distance[u]+wt,distance[v]);
            }
        }
        
        for(int i=0;i<N;++i)
        {
            if(distance[i]==INT_MAX)
            distance[i] = -1;
        }
        return distance;
        
        
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends