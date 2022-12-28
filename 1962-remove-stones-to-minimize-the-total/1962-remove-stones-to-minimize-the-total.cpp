class Solution {
public:
    int minStoneSum(vector<int>& piles, int k)
    {
        priority_queue<int>pq(piles.begin(),piles.end());
        int size = piles.size();
        int sum = 0;
        
        while(k--)
        {
            int temp = pq.top();
            pq.pop();
            temp -= floor(temp/2);
            pq.push(temp);
        }
        
        while(pq.empty()==false)
        {
           sum += pq.top();
            pq.pop();
        }
            
        return sum;
            
    }
};