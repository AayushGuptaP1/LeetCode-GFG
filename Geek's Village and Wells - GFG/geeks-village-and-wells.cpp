//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> chefAndWells(int m,int n,vector<vector<char>> &c)
    {
        vector<vector<int>> res(m,vector<int>(n,-1));
        queue<pair<int,int>> q;
        int traverse[5] = {-1,0,1,0,-1};
        
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(c[i][j] == 'W')
                {
                    q.push({i,j});
                    res[i][j] = 0;
                    
                }
                else if(c[i][j] == 'N')
                res[i][j] = 0;
                
            }
        }
        
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i=0;i<4;++i)
            {
                int dRow = row + traverse[i];
                int dCol = col + traverse[i+1];
                
                if(dRow>=0 && dRow<m && dCol>=0 && dCol<n && c[dRow][dCol] != 'N' && res[dRow][dCol] == -1)
                {
                    res[dRow][dCol] = 2 + res[row][col];
                    
                    q.push({dRow,dCol});
                }
            }
        }
        
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(c[i][j] == '.')
                res[i][j] = 0;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends