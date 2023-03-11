class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<vector<pair<int,int>>> graph(n);
        vector<int> distance(n,INT_MAX);
        distance[src] = 0;
        int stop = 0;
       
        
        for(auto &it : flights)
        {
            graph[it[0]].push_back({it[1],it[2]});
        }
        
        queue<pair<int,int>>pq;
        pq.push({0,src});
        
        while(!pq.empty()  )
        {
            if(stop>k)
                break;
            int size = pq.size();
            for(int i=0;i<size;++i)
            {
                int dist = pq.front().first;
                int node = pq.front().second;
                pq.pop();
                
                for(auto &it : graph[node])
                {
                    int adjNode = it.first;
                    int edgeWeight = it.second;
                    
                    if(dist+edgeWeight < distance[adjNode])
                    {
                        distance[adjNode] = dist+edgeWeight;
                        
                        pq.push({distance[adjNode],adjNode});
                    }
                }
            }
            stop++;
        }
        return distance[dst]==INT_MAX? -1 : distance[dst];
    }
};