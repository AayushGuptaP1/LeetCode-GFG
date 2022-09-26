class Solution {
public:
    int mySqrt(int x) 
    {
        long long low = 1,  high = x, ans;
        
        while(low<= high)
        {
           long long mid = (low+high)/2;
            
            if(mid*mid <= x)
            {
               ans = mid;
               low = mid+1;
               
            }
            else
            high = mid-1;
        }
        return ans;
    }
};