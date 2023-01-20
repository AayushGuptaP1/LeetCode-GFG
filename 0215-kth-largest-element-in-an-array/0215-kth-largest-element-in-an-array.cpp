class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int,vector<int>,greater<int>>pq(begin(nums),begin(nums)+k);
        
        int size = nums.size();
        
        for(int i=k;i<size;++i)
        {
            if(nums[i]>pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};