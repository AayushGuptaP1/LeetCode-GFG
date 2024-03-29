class Solution {
private:
    bool isPossible(int mid, vector<int>& bloomDay, int m, int k)
    {
        int flowers = 0, bouquets = 0;
        
        for(const int& x : bloomDay)
        {
            if(x <= mid)
                flowers++;
            else
                flowers = 0;
            if(flowers == k)
            {
                bouquets++;
                flowers = 0;
            }
        }
        return bouquets>=m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k)
    {
        long minSize = (long)m*(long)k;
        long gardenSize = bloomDay.size();
        if( gardenSize < minSize)
            return -1;
        int low = 1, high = *max_element(begin(bloomDay),end(bloomDay)), mid;
        
        while(low < high)
        {
            mid = (low+high)>>1;
            
            if(isPossible(mid,bloomDay,m,k))
                high = mid;
            else
                low = mid+1;
        }
        return high;
    }
};