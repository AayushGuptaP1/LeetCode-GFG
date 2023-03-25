//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int startX = KnightPos[0];
	    int startY = KnightPos[1];
	    int targetX = TargetPos[0];
	    int targetY = TargetPos[1];
	    int traverse[10] = {-1,-2,-2,-1,1,2,2,1,-1,-2};
	    
	    queue<pair<int,pair<int,int>>> q;
	    vector<vector<bool>> visited(N+1,vector<bool>(N+1,false));
	    q.push({0,{startX,startY}});
	    visited[startX][startY] = true;
	    
	    
	    while(!q.empty())
	    {
	        int time = q.front().first;
	        int row = q.front().second.first;
	        int col = q.front().second.second;
	        q.pop();
	        
	        if(row == targetX && col == targetY)
	        return time;
	        
	        for(int i=0;i<8;++i)
	        {
	            int dRow = row + traverse[i];
	            int dCol = col + traverse[i+2];
	            
	            if(dRow>=0 && dRow<=N && dCol>=0 && dCol<=N && visited[dRow][dCol] == false)
	            {
	                q.push({time+1,{dRow,dCol}});
	                visited[dRow][dCol] = true;
	            }
	        }
	    }
	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends