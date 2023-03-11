//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) 
    {
        int m  = heights.size();
        int n = heights[0].size();
        int traverse[5] = {0,-1,0,1,0};
        vector<vector<int>> distances(m,vector<int>(n,INT_MAX));
        distances[0][0] = 0;
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        
        while(!pq.empty())
        {
            int effort = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            
            if(row==m-1 && col == n-1)
            return effort;
            
            for(int i=0;i<4;++i)
            {
                int dRow = row + traverse[i];
                int dCol = col + traverse[i+1];
                
                if(dRow>=0 && dRow<m && dCol>=0 && dCol<n)
                {
                    int diff = abs(heights[row][col]-heights[dRow][dCol]);
                    diff = max(effort,diff);
                    if(diff< distances[dRow][dCol])
                    {
                        distances[dRow][dCol] = diff;
                        pq.push({diff,{dRow,dCol}});
                    }
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends