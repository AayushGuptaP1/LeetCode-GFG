class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) 
    {
        vector<vector<pair<int,int>>> graph(n);
        vector<long long> distance(n,LONG_MAX);
        vector<long long> ways(n,0);
        distance[0] = 0;
        ways[0] = 1;
        
        
        for(auto &x : roads)
        {
            graph[x[0]].push_back({x[1],x[2]});
            graph[x[1]].push_back({x[0],x[2]});
        }
        
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        pq.push({0,0});
        
        while(!pq.empty())
        {
            long long dist = pq.top().first;
            long long node = pq.top().second;
            pq.pop();
            
            for(auto &x : graph[node])
            {
                long long adjNode = x.first;
                long long edWt = x.second;
                
                
                   if(dist + edWt < distance[adjNode] )
                    {
                        distance[adjNode] = dist + edWt;
                        pq.push({distance[adjNode],adjNode});
                        ways[adjNode] = ways[node];
                    }
                    else if(dist + edWt == distance[adjNode])
                    {
                        ways[adjNode] = (ways[adjNode]+ ways[node])%1000000007;
                    }
                      
                
                
                
                
            }
        }
        return ways[n-1];
    }
};