//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int k)
    {
        deque<int> pq;
        for(int i=1;i<=N;++i)
        pq.push_back(i);
        int count = N;
        
        while(pq.size()>1)
        {
            for(int i=0;i<k;++i)
            {
                pq.pop_front();
                count--;
                if(count == 1)
                return pq.front();
            }
            for(int i=0;i<k;++i)
            {
                pq.pop_back();
                count--;
                if(count == 1)
                return pq.front();
            }
        }
        return pq.front();
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends