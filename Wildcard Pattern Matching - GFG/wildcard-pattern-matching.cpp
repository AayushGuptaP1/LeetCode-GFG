//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    int wildCard(string p,string s)
    {
        int m = s.length();
        int n = p.length();
        vector<bool>prev(n+1,false), curr(n+1,false);
        prev[0] = true;
        for(int j=1;j<=n;++j)
        {
            if(p[j-1] == '*')
                prev[j] = true;
            else
                break;
        }
        
         for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
                {
                    if(s[i-1] == p[j-1] || p[j-1] == '?')
                        curr[j] =  prev[j-1];
                    else if(p[j-1] == '*')
                    {
                        bool take = curr[j-1];
                        bool notTake = prev[j];
                        curr[j] =take | notTake;
                    }
                    else
                        curr[j] =  false;
                }
                prev = curr;
        }
        
        
        return prev[n];
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends