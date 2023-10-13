class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n = cost.size();
        int first = cost[0],second = cost[1];
        
        for(int index=2;index<n;++index)
        {
            int one = first;
            int two = INT_MAX;
            if(index-2>=0)
                two =  second;
            int curr =  min(one,two) + cost[index]; 
            first = second;
            second = curr;
        }
        return min(first,second);
    }
};