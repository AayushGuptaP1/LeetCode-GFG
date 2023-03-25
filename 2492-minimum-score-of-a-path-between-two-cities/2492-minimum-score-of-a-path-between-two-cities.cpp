class Solution {
private:
    
    void dfs(int source, vector<vector<pair<int,int>>> &graph, vector<bool> &visited, int &res)
    {
        visited[source] = true;
        
        for(auto &x : graph[source])
        {
            int adjNode = x.first;
            int edWt = x.second;
            
            res = min(res,edWt);
            
            //take minimum of every edWt in the graph of the component.
            
            // only push those nodes who are not visited but take account for the edges of every node
            
            if(visited[adjNode]==false)
                dfs(adjNode,graph,visited,res); 
        }
        
    }
public:
    int minScore(int n, vector<vector<int>>& roads) 
    {
        int res = INT_MAX;
        vector<vector<pair<int,int>>> graph(n+1);
        
        for(auto &x : roads)
        {
            graph[x[0]].push_back({x[1],x[2]});
            graph[x[1]].push_back({x[0],x[2]});
        }
        
        vector<bool> visited(n+1,false);
        
        dfs(1,graph,visited,res);
        return res;
    }
};