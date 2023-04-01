//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    private:
    void generate(string str,vector<string>&res, int left, int right)
    {
        if(left == 0 && right == 0)
        {
            res.push_back(str);
            return;
        }
        if(left>0)
        generate(str+"(",res,left-1,right);
        if(right>left)
        generate(str+")",res,left,right-1);
    }
    public:
    vector<string> AllParenthesis(int n) 
    {
        vector<string> res;
        generate("",res,n,n);
        return res;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends