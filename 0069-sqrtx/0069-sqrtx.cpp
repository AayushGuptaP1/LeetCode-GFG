class Solution {
public:
    int mySqrt(int x)
    {
        long long low = 1, high = x, mid;
        
        while(low <= high)
        {
            mid = (low+high)>>1;
            
            if(mid*mid <= x)
                low = mid+1;
            else
                high = mid-1;
        }
        return high;
    }
};