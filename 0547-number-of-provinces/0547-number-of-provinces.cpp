class Solution {
private:
    void bfs(int u, vector<vector<int>> &isConnected, vector<bool> &visited)
    {
        visited[u] = true;
        int n = isConnected.size();
        queue<int>q;
        q.push(u);
        
        while(q.empty()==false)
        {
            int temp = q.front();
            q.pop();
            
            for(int i=0;i<n;++i)
            {
                if(isConnected[temp][i]==1 && visited[i] == false)
                {
                    visited[i] = true;
                    q.push(i);
                }
                
            }
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
                    bfs(j,isConnected,visited);
                }
                    
            
        }
        return count;
    }
};