class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) 
    {
        int n = happiness.size();
        long long res = 0;
        priority_queue<int> pq(begin(happiness),end(happiness));
        
        
        for(int i=0;i<k;++i)
        {
            res += max(0,pq.top()-i);
            pq.pop(); 
        }
        return res;
        
    }
};