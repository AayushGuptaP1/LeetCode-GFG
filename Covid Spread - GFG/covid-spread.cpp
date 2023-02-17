//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> grid)
    {
         int m = grid.size();
        int n = grid[0].size();
        
        int fresh = 0;
        int res = 0;
        queue<pair<pair<int,int>,int>>q;
        
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j]==2)
                    q.push({{i,j},0});
                else if(grid[i][j]==1)
                    fresh++;
            }
        }
        
        while(q.empty()==false)
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            
            res = max(res,time);
            
            if(row-1>=0 && row-1<m && grid[row-1][col]==1 )
            {
                q.push({{row-1,col},time+1});
                grid[row-1][col] = 0;
                fresh--;
            }
            if(row+1>=0 && row+1<m && grid[row+1][col]==1)
            {
                q.push({{row+1,col},time+1});
                grid[row+1][col] = 0;
                fresh--;
            }
            if(col-1>=0 && col-1<n && grid[row][col-1]==1)
            {
                q.push({{row,col-1},time+1});
                grid[row][col-1] = 0;
                fresh--;
            }
            if(col+1>=0 && col+1<n && grid[row][col+1]==1)
            {
                q.push({{row,col+1},time+1});
                grid[row][col+1] = 0;
                fresh--;
            }
        }
        return fresh==0? res : -1;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends