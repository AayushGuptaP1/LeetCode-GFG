//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> &A, int X, int Y) 
    {
        queue<pair<pair<int,int>,int>>q;
        if(A[0][0] == 0 || A[X][Y] == 0)
        return -1;
        int traverse[] = {-1,0,1,0,-1};
        
        q.push({{0,0},0});
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            
            if(row==X && col==Y)
            return time;
            for(int i=0;i<4;++i)
            {
                int dRow = row+ traverse[i];
                int dCol = col + traverse[i+1];
                
                if(dRow>=0 && dRow<N && dCol>=0 && dCol<M && A[dRow][dCol] == 1)
                {
                   q.push({{dRow,dCol},time+1});
                    A[dRow][dCol] = 0;
                    
                }
            }

        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends