class Solution {
private:
    void dfs(int node, vector<vector<int>> &graph, vector<int> &path, vector<vector<int>> &ans)
    {
        path.push_back(node);
        if(path.back() == graph.size()-1)
        {
            ans.push_back(path);
            path.pop_back();
            return;
        }
        
        
        for(auto &x : graph[node])
            dfs(x,graph,path,ans);
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(0,graph,path,ans);
        return ans;
        
    }
};