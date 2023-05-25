class Solution {
public:
    int climbStairs(int n) 
    {
        if(n<=3)
            return n;
        int prev = 3, prev2 = 2,ways = 0;
        
        for(int i=4;i<=n;++i)
        {
            ways = prev + prev2;
            prev2 = prev;
            prev = ways;
        }
        return ways;
    }
};