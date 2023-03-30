//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
 void uniqueSet(vector<int> &candidates,int index,int target,vector<int> &ans,vector<vector<int>> &res)
    {
        if(target<0 || index == candidates.size())
            return;
        if(target==0)
        {
            res.push_back(ans);
            
            return;
        }
        
        ans.push_back(candidates[index]);
        uniqueSet(candidates,index,target-candidates[index],ans,res);
        
        ans.pop_back();
        uniqueSet(candidates,index+1,target,ans,res);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        unordered_set<int> st(begin(candidates),end(candidates));
        candidates.assign(begin(st),end(st));
        sort(begin(candidates), end(candidates));
        vector<vector<int>> res;
        vector<int> ans;
        uniqueSet(candidates,0,target,ans,res);
        
        
        return res;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends