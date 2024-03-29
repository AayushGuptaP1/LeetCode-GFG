class Solution {
private:
    bool isPossible(int mid , const vector<int>&weights, int days)
    {
        int total=0, count = 1;
        
        for(const int &x : weights)
        {
            if(total + x > mid)
            {
                count++;
                total = 0;
            }
            total += x;
        }
        return count<=days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int low = *max_element(begin(weights),end(weights));
        int high = accumulate(begin(weights),end(weights),0), mid;
        
        while(low < high)
        {
            mid = (low+high)>>1;
            
            if(isPossible(mid,weights,days))
                high = mid;
            else
                low = mid+1;            
        }
        return high;
        
    }
};