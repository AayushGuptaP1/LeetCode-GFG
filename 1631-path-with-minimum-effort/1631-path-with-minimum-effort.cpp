class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int m = heights.size();
        int n = heights[0].size();
        int traverse[] = {0,-1,0,1,0};
        
        vector<vector<int>> distances(m,vector<int>(n,INT_MAX));
        distances[0][0] = 0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        
        while(!pq.empty())
        {
            int effort = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            
            for(int i=0;i<4;++i)
            {
                int dRow = row + traverse[i];
                int dCol = col + traverse[i+1];
                
                if(dRow>=0 && dRow<m && dCol>=0 && dCol<n)
                {
                    int difference = abs(heights[row][col]-heights[dRow][dCol]);
                    difference = max(effort,difference);
                    if(difference < distances[dRow][dCol])
                    {
                        distances[dRow][dCol] = difference;
                        pq.push({difference,{dRow,dCol}});
                        
                    }
                    
                }
            }
        }
        return distances[m-1][n-1];
    }
};