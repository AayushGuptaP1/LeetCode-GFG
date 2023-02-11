class Solution {
private:
    bool bfs(int i, vector<vector<int>> &graph, vector<int> &colors)
    {
        
        queue<int> q;
        q.push(i);
        colors[i] = 0;
        while(q.empty()==false)
        {
            int temp = q.front();
            q.pop();
            
            for(int &u : graph[temp])
            {
                if(colors[u] == -1)
                {
                    colors[u] = colors[temp]^1;
                    q.push(u);
                }
                else if(colors[u] == colors[temp])
                    return false;
            }
            
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph)
    {
        int n = graph.size();
        vector<int> colors(n,-1);
        
        
        
        
        for(int i=0;i<n;++i)
        {
            if(colors[i]== -1)
            {
                if(!bfs(i,graph,colors))
                    return false;
            }
                
        }
        return true;
        
       
        
        
    }
};