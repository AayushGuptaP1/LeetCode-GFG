class Solution {
private:
bool dfs(int u,vector<vector<int>>& graph,vector<bool>&visited,vector<bool> &recSt)
{
    visited[u] = true;
    recSt[u] = true;
    
    for(auto &x : graph[u])
    {
        if(visited[x]==false)
        {
            if(dfs(x,graph,visited,recSt)==false)
                return false;
        }
        else if(recSt[x]==1)
            return false;
    }
    recSt[u] = false;
    return true;
}
      
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        int m = graph.size();
        vector<int> res;
        
        vector<bool> visited(m,false);
        vector<bool> recSt(m);
        
        for(int i=0;i<m;++i)
        {
            if(visited[i]==false)
                dfs(i,graph,visited,recSt);
        }
        for(int i=0;i<m;++i)
            if(recSt[i]==false)
                res.push_back(i);
        return res;
    }
};