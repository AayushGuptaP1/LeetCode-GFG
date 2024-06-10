class Solution {
public:
    int heightChecker(vector<int>& heights) 
    {
        int count = 0;
        
        priority_queue<int,vector<int>,greater<int>> pq(begin(heights),end(heights));
        
        for(auto &x : heights)
        {
            if(x != pq.top())
                count++;
            pq.pop();
        }
        return count;           
        
    }
};