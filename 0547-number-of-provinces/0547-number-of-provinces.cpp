class Solution {
private:
    void dfs(int u, vector<vector<int>> &isConnected, vector<bool> &visited)
    {
        visited[u] = true;
        int n = isConnected.size();
        for(int i=0;i<n;++i)
        {
            if(isConnected[u][i]==1 &&visited[i]==false)
                dfs(i,isConnected,visited);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n = isConnected.size();
        vector<bool>visited(n,false);
        int count = 0;
        
        
            for(int j=0;j<n;++j)
            {
                if(visited[j] == false)
                {
                    count++;
                    dfs(j,isConnected,visited);
                }
                    
            
        }
        return count;
    }
};