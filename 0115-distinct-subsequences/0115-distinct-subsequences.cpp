class Solution {
public:
    int numDistinct(string s, string t)
    {
        int m = s.length();
        int n = t.length();
        vector<double> prev(n+1,0), curr(n+1,0);
        prev[0] = curr[0] = 1;        
        
        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                double notTake = prev[j];
                double take = 0;
                if(s[i-1] == t[j-1])
                    take = prev[j-1];
                curr[j] = take+notTake;
            }
            prev = curr;
        }
        return(int) curr[n];
        
    }
};