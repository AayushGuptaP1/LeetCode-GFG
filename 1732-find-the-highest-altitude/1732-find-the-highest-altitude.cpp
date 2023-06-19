class Solution {
public:
    int largestAltitude(vector<int>& gain) 
    {
        int n = gain.size();
        int res = 0;
        int prev = 0;
        
        for(int i=0;i<n;++i)
        {
            prev += gain[i];
            res = max(res,prev);
        }
        return res;
    }
};