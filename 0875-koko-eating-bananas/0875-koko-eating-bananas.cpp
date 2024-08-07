class Solution {
private:
    bool isPossible(const int mid, vector<int> & piles,const int h)
    {
        int res = 0;
        for(const auto &x : piles)
        {
            res += x/mid + (x%mid != 0);
            if(res > h)
                return false;
        }          
        return res<=h;        
    }
public:
    int minEatingSpeed(vector<int>& piles, int h)
    {
        int low = 1, high = *max_element(begin(piles),end(piles)), mid;
        
        while(low <  high)
        {
            mid = (low+high)>>1;
            
            if(isPossible(mid,piles,h))
                high = mid;
            else
                low = mid+1;
        }
        return high;
    }
};