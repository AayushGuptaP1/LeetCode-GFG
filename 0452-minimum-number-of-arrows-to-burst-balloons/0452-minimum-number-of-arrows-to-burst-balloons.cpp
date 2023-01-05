class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        sort(begin(points),end(points));
        int count = 1;
        int size = points.size();
        int mini = points[0][1];
        
        for(int i=1;i<size;++i)
        {
            if(mini<points[i][0])
            {
                count++;
                mini = points[i][1];
            }
            mini = min(mini, points[i][1]); 
                
        }
        return count;
    }
};