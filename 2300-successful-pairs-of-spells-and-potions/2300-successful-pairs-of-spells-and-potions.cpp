class Solution {
    private:
    int binarySearch(vector<int> &potions, int target, long long success)
    {
        int index = -1;
        int low = 0, high = potions.size()-1;
        
        while(low <= high)
        {
            int mid = (low+high)>>1;
            long long res =(long long) target*potions[mid];
            
            if(res<success)
                low = mid+1;
            else if(res>=success)
            {
                index = mid;
                high = mid-1;
            }
        }
        
            return(index == -1)? 0 : potions.size()-index;
         
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success)
    {
        vector<int> ans;
        sort(begin(potions),end(potions));
        
        for(auto & x : spells)
        {
            int pairs = binarySearch(potions,x,success);
            ans.push_back(pairs);
        }
        return ans;
    }
};