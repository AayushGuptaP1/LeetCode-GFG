//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  
    {
        vector<vector<pair<int,int>>> graph(n);
        vector<int> distance(n,INT_MAX);
        distance[src] = 0;
        queue<pair<int,int>>q;
        q.push({0,src});
        int stop = 0;
        
        for(auto &x : flights)
        {
            graph[x[0]].push_back({x[1],x[2]});
        }
        
        while(!q.empty())
        {
            if(stop>K)
            break;
            
            int size = q.size();
            
            for(int i=0;i<size;++i)
           { 
               int dist = q.front().first;
                int node = q.front().second;
                q.pop();
                
                for(auto &x : graph[node])
                {
                    int adjNode = x.first;
                    int edgeWeight = x.second;
                    
                    if(dist+edgeWeight < distance[adjNode])
                    {
                        distance[adjNode] = dist + edgeWeight;
                        q.push({distance[adjNode],adjNode});
                    }
                }
               
           }
           stop++;
        }
        return distance[dst]==INT_MAX ? -1 : distance[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends