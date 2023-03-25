//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	   vector<bool> visited(V,false);
	   queue<int> q;
	   
	   int level = 0;
	   q.push(0);
	   visited[0] = true;
	   
	   while(!q.empty())
	   {
	       int size = q.size();
	       
	       for(int i=0;i<size;++i)
	       {
	           int node = q.front();
	           q.pop();
	           if(node == X)
	           return level;
	           
	           for(auto &x : adj[node])
	           {
	               if(visited[x] == false)
	               {
	                   q.push(x);
	                   visited[x] = true;
	               }
	           }
	       }
	       level++;
	   }
	   return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends