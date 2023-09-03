//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int n, int amount) 
	{ 
        vector<int>curr(amount+1,1e5);
        
        for(int i=0;i<=amount;++i)
        {
            if(i%coins[0] == 0)
                curr[i] = i/coins[0];
        }
        
        for(int i=1;i<n;++i)
        {
            for(int j=0;j<=amount;++j)
            {
                int notTake = curr[j];
                int take = 1e5;
                if(j>=coins[i])
                    take = 1+curr[j-coins[i]];
                
                curr[j] = min(take,notTake);
            }
        }
        int ans = curr[amount];
        
        if(ans >= 1e5)
            return -1;
        return ans;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends