class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        vector<int> inEdges(n+1,0), outEdges(n+1,0);
        
        for(auto &x : trust)
        {
            outEdges[x[0]]++;
            inEdges[x[1]]++;
        }
        for(int i=1;i<=n;++i)
            if(outEdges[i] == 0 && inEdges[i] == n-1)
                return i;              
        return -1;
        
    }
};