class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        vector<vector<int>> distance(n,vector<int>(n,1e8));
        for(int i=0;i<n;++i)
            distance[i][i] = 0;
        int res = -1;
        int ans = INT_MAX;
        for(auto &x : edges)
        {
            distance[x[0]][x[1]] = x[2];
            distance[x[1]][x[0]] = x[2];
        }
        
        for(int w=0;w<n;++w)
        {
            for(int u=0;u<n;++u)
            {
                for(int v=0;v<n;++v)
                {
                    distance[u][v] = min(distance[u][w]+distance[w][v],distance[u][v]);
                }
            }
        }
        
        for(int i=0;i<n;++i)
        {
            int count = 0;
            for(int j=0;j<n;++j)
            {
                if(distance[i][j]<=distanceThreshold)
                    count++;
            }
            if(count<=ans)
            {
                ans = count;
                res = i;
            }
            
        }
        return res;
        
    }
};