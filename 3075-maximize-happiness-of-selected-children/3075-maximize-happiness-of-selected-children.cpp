class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) 
    {
        long long res = 0;
        sort(begin(happiness),end(happiness),greater<int>());        
        
        for(int i=0;i<k;++i)
            res += max(0,happiness[i]-i);
        
        return res;
        
    }
};