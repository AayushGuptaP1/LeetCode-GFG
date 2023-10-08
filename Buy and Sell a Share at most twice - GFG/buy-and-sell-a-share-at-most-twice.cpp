//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++




    int maxProfit(vector<int>& prices) 
    {
         int n = prices.size();
        vector<vector<int>> curr(2,vector<int>(3,0));
        
        for(int index = n-1;index>=0;--index)
        {
            for(int buy = 0;buy<=1;++buy)
            {
                for(int limit = 1;limit<=2;++limit)
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
        
        return curr[1][2];
    }

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends