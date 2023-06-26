class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) 
    {
        
        long long res = 0;
        int begin = 0;
        int end = costs.size()-1;
        priority_queue<int,vector<int>,greater<int>> pq1;
        priority_queue<int,vector<int>,greater<int>> pq2;  
        
        while(k--)
        {
            while(pq1.size()< candidates && begin<=end)
               pq1.push(costs[begin++]);
            while(pq2.size()< candidates && begin<=end)
                pq2.push(costs[end--]);
            
            int top1 = pq1.size()>0? pq1.top() : INT_MAX ;
            int top2 = pq2.size()>0? pq2.top(): INT_MAX ;
            
            if(top1<= top2)
            {
                res += top1;   
                pq1.pop();
            }
            else
            {
                res += top2;
                pq2.pop();
            
            }
        }
       
        return res;
    }
};