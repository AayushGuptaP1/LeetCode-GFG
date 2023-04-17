class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        int n = candies.size();
        vector<bool> ans;
        int maxCandy = 0;
        
        for(int i=0;i<n;++i)
        {
            maxCandy = max(maxCandy,candies[i]);
        }
        
        int high = maxCandy - extraCandies;
        
        for(int i=0;i<n;++i)
            ans.push_back(candies[i]>=high);
        return ans;
            
    }
};