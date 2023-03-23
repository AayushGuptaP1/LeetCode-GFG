class Solution {
private:
    void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited)
    {
        visited[node] = true;
        
        for(auto &x : graph[node])
        {
            if(visited[x] == false)
                dfs(x,graph,visited);
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        vector<bool> visited(n,false);
        vector<vector<int>> graph(n);
        int cables = 0;
        int components = 0;
        
        for(auto &x : connections)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
            cables++;
        }
        
        for(int i=0;i<n;++i)
        {
            if(visited[i] == false)
            {
                components++;
                dfs(i,graph,visited);
            }
        }
        
                
        if(cables< n-1)
            return -1;            
        else
            return components-1;
            
        
    }
};