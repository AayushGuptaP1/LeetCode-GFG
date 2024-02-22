class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        vector<int> netTrust(n+1,0);
        
        for(auto &x : trust)
        {
            netTrust[x[0]]--;
            netTrust[x[1]]++;
        }
        for(int i=1;i<=n;++i)
            if(netTrust[i] == n-1)
                return i;              
        return -1;
        
    }
};