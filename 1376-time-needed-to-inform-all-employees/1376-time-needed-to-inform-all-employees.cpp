class Solution {
private:
    int  dfs(int node, vector<vector<int>> &graph, vector<int> &informTime)
    {
        int res = 0;
        
        for(auto &x : graph[node])
            res = max(dfs(x,graph,informTime),res);
        
        return res+informTime[node];
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)
    {
        vector<vector<int>> graph(n);
        
        for(int i=0;i<n;++i)
        {
            if(manager[i]!= -1)
            graph[manager[i]].push_back(i);
        }
        
        return dfs(headID,graph,informTime);
    }
};