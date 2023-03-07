class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end)
    {
        vector<vector<pair<int,double>>> graph(n);
        vector<double> probability(n,0.0);
        probability[start] = 1.0;
        int size = edges.size();
        
        for(int i=0;i<size;++i)
        {
            graph[edges[i][0]].push_back({edges[i][1],succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start});
        
        while(!pq.empty())
        {
            double prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto &x : graph[node])
            {
                int adjNode = x.first;
                double probWt = x.second;
                
                if(prob*probWt > probability[adjNode])
                {
                    probability[adjNode] = prob*probWt;
                    pq.push({probability[adjNode],adjNode});
                }
            }
        }
        
        if(probability[end]==2)
            return 0;
        return probability[end];
    }
};