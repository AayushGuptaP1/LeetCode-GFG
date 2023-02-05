//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
private :
void dfs(int u, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[u] = true;
    int n = adj.size();
    
    for(int i=0;i<n;++i)
    {
        if(adj[u][i]==1 && visited[i]==false)
        dfs(i,adj,visited);
    }
}
  public:
    int numProvinces(vector<vector<int>> adj, int V) 
    {
        vector<bool>visited(V,false);
        int count = 0;
        
        for(int i=0;i<V;++i)
        {
            if(visited[i]==false)
            {
                count++;
                dfs(i,adj,visited);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends