//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> hospital)
    {
        int m = hospital.size();
        int n = hospital[0].size();
        int uninfected = 0;
        int res = 0;
        
        queue<pair<pair<int,int>,int>>q;
        int traverse[5] = {-1,0,1,0,-1};
        
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(hospital[i][j]==2)
                q.push({{i,j},0});
                else if(hospital[i][j]==1)
                uninfected++;
            }
        }
        
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            
            res = max(res,time);
            
            for(int i=0;i<4;++i)
            {
                int delRow = row + traverse[i];
                int delCol = col + traverse[i+1];
                
                if(delRow>=0 && delRow<m && delCol>=0 && delCol<n && hospital[delRow][delCol]==1)
                {
                    q.push({{delRow,delCol},time+1});
                    hospital[delRow][delCol] = 2;
                    uninfected--;
                }
            }
        }
        return uninfected==0?res : -1;
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