//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findMinCost(string word1, string word2, int costX, int costY)
	{
	   int m = word1.length();
        int n = word2.length();
        
        vector<int> prev(n+1,0), curr(n+1,0);
        
        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(word1[i-1] == word2[j-1])
                    curr[j] = 1 + prev[j-1];
                else
                    curr[j] = max(curr[j-1],prev[j]);
            }
            prev = curr;
        }
        
        return (m-curr[n])*costX +(n-curr[n])*costY;
	}
  

};
	

//{ Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
       	string x, y;
       	cin >> x >> y;
        
       	int costX, costY;
       	cin >> costX >> costY;

        

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends