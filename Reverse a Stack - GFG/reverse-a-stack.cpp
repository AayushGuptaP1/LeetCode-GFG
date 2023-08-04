//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void Insert(stack<int> &St, int temp){
        if(St.empty() == true){
            St.push(temp);
            return;
        }
        else{
            int num = St.top();
            St.pop();
            Insert(St,temp);
            St.push(num);
            return;
        }
    }
    stack<int> Reverse(stack<int> &St)
    {
        if(St.size()==1)
        return St;
        else{
            int temp = St.top();
            St.pop();
            Reverse(St);
            Insert(St,temp);
            return St;
        }
    }
};


//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends