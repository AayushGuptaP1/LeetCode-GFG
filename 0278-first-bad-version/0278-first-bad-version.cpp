// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) 
    {
        long long low = 1, high = n, mid;
        
        while(low < high)
        {
            mid = (low+high)>>1;
            
            if(isBadVersion(mid))            
                high = mid;
            else
                low = mid+1;
            
        }
        return low;
    }
};