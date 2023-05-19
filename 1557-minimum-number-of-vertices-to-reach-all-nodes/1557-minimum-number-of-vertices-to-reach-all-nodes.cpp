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
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) 
    {
        vector<int> dependencies(n,0);        
        vector<vector<int>> graph(n);
        vector<bool> visited(n);
        vector<int> res;
        queue<int> q;
        
        for(auto &x : edges)
        {
            graph[x[0]].push_back(x[1]);
            dependencies[x[1]]++;
        }
        
        for(int i=0; i<n;++i)
        {
            if(dependencies[i] == 0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto &x : graph[node])
            {
                dependencies[x]--;
                if(dependencies[x] == 0)
                    q.push(x);
            }
            
            if(visited[node] == false)
            {
                res.push_back(node);
                dfs(node,graph,visited);
            }
                
        }
        return res;
        
        
    }
};