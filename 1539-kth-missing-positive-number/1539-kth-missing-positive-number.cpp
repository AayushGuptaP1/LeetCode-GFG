class Solution {
public:
    int findKthPositive(vector<int>& arr, int k)
    {
        int low = 0, high = arr.size(), mid;
        
        while(low < high)
        {
            mid = (low+high)>>1;
            
            if(arr[mid]-mid-1 < k)
                low = mid+1;
            else
                high = mid;
        }
        return low+k;
    }
};