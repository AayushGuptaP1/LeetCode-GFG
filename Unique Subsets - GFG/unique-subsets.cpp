//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    private:
    void generateSubsets(vector<int> &arr,int index,vector<int> &current, vector<vector<int>> &ans)
    {
        ans.push_back(current);
        
        for(int i=index;i<arr.size();++i)
        {
            if(i == index || arr[i] != arr[i-1])
            {
                current.push_back(arr[i]);
                generateSubsets(arr,i+1,current,ans);
                current.pop_back();
            }
        }
    }
    public:
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        sort(begin(arr),end(arr));
        vector<int> current;
        vector<vector<int>> ans;
        generateSubsets(arr,0,current,ans);
        return ans;
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
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
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