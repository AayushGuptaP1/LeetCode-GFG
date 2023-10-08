//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    int findProfit(int prices[], int buy, int limit, int index, int size,vector<vector<vector<int>>> &dp)
    {
        if(index == size || limit == 0)
            return 0;
        if(dp[index][buy][limit] != -1)
            return dp[index][buy][limit];
        int profit = 0;
        if(buy && limit)
        {
            profit = max(-prices[index] + findProfit(prices,0,limit,index+1,size,dp),0+findProfit(prices,1,limit,index+1,size,dp));
        }
        else if(buy ==0 && limit)
        {
            profit = max(prices[index]+findProfit(prices,1,limit-1,index+1,size,dp),0+findProfit(prices,0,limit,index+1,size,dp));
        }
        return dp[index][buy][limit] =  profit;
    }
  public:
    int maxProfit(int k, int n, int prices[])
    {
        vector<vector<int>> curr(2,vector<int>(k+1,0));
        
        for(int index = n-1;index>=0;--index)
        {
            for(int buy = 0;buy<=1;++buy)
            {
                for(int limit = 1;limit<=k;++limit)
                {
                    int profit = 0;
                    if(buy)
                    {
                        profit = max(-prices[index]+curr[0][limit],curr[1][limit]);
                    }
                    else
                    {
                        profit = max(prices[index]+ curr[1][limit-1],curr[0][limit]);
                    }
                    curr[buy][limit] = profit;
                }
            }
        }
        
        return curr[1][k];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends