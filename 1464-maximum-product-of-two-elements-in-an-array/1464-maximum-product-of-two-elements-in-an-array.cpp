class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int n = nums.size();
        
        priority_queue<int,vector<int>,greater<int>> pq(nums.begin(),nums.begin()+2);
        
        for(int i=2;i<n;++i)
        {
            if(nums[i] > pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        int res = pq.top()-1;
        pq.pop();
        
        res *= pq.top()-1;
        return res;
        
        
        
        
    }
};