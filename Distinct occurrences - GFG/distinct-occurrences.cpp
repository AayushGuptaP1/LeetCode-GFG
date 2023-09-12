//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/
int MOD = 1e9+7;
class Solution
{
    public:
    int subsequenceCount(string s, string t)
    {
        int m = s.length();
        int n = t.length();
        vector<int> prev(n+1,0);
        prev[0] = 1;        
        
        for(int i=1;i<=m;++i)
        {
            for(int j=n;j>=1;--j)
            {
                int notTake = prev[j];
                int take = 0;
                if(s[i-1] == t[j-1])
                    take = prev[j-1];
                prev[j] = (take+notTake)%MOD;
            }
            
        }
        return prev[n];
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends