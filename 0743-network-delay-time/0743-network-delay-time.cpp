class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        int ans = 0;
        vector<vector<pair<int,int>>>graph(n+1);
        vector<int> distances(n+1,INT_MAX);
        distances[k] = 0;
        
        for(auto &x : times)
        {
            graph[x[0]].push_back({x[1],x[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        pq.push({0,k});
        
        while(!pq.empty())
        {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto &it : graph[node])
            {
                int adjNode = it.first;
                int edgeWeight = it.second;
                
                if(dist + edgeWeight < distances[adjNode])
                {
                    distances[adjNode] = dist+edgeWeight;
                    pq.push({distances[adjNode],adjNode});
                }
            }
        }
        for(int i=1;i<=n;++i)
        {
            if(distances[i] == INT_MAX)
                return -1;
            else 
                ans = max(ans,distances[i]);
        }
        return ans;
    }
};