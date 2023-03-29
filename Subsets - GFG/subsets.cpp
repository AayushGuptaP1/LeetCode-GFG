//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    private:
    void subSetGenerate(vector<int> &a,int index, vector<int> &set, vector<vector<int>> &ans)
    {
        if(index == a.size())
        {
            ans.push_back(set);
            return;
        }
        
        set.push_back(a[index]);
        subSetGenerate(a,index+1,set,ans);
        set.pop_back();
        subSetGenerate(a,index+1,set,ans);
    }
    public:
    vector<vector<int> > subsets(vector<int>& A)
    {
        vector<vector<int>> ans;
        vector<int> set;
        subSetGenerate(A,0,set,ans);
        sort(begin(ans),end(ans));
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
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}
// } Driver Code Ends