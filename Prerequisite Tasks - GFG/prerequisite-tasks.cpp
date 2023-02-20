//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) 
	{
	   int tasks = 0;
	   int size  = prerequisites.size();
	   vector<int> dep(N,0);
	   queue<int>q;
	   
	   vector<vector<int>> graph(N);
	   
	   for(auto &x : prerequisites)
	   {
	       graph[x.second].push_back(x.first);
	       dep[x.first]++;
	   }
	   for(int i=0;i<N;++i)
	   {
	       if(dep[i]==0)
	       q.push(i);
	   }
	   
	   while(!q.empty())
	   {
	       int node = q.front();
	       q.pop();
	       ++tasks;
	       
	       for(auto &x : graph[node])
	       {
	           dep[x]--;
	           if(dep[x]==0)
	           q.push(x);
	       }
	   }
	   return tasks==N;
	   
	   
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends