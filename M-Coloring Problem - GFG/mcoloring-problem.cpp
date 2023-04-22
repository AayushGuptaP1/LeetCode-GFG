//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
private:
bool isSafe(int node,int col,vector<int>&color, vector<vector<int>>&G)
{
    for(auto &x : G[node])
    {
        if(color[x] == col)
        return false;
    }
    return true;
}

bool canColor(int node, int m,int n,vector<vector<int>> &G,vector<int> &color)
{
    if(node == n)
    return true;
    
    for(int i=1;i<=m;++i)
    {
        if(isSafe(node,i,color,G))
        {
            color[node] = i;
            if(canColor(node+1,m,n,G,color))
            return true;
        }
    }
    return false;
}
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n)
    {
        vector<vector<int>> G(n);
        vector<int> color(n);
        
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(graph[i][j] == 1)
                {
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        }
        return canColor(0,m,n,G,color);
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends