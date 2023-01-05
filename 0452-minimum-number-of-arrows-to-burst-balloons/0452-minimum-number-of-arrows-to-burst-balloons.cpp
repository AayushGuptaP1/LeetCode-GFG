class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        sort(begin(points),end(points));
        int arrows = 1;
        int size = points.size();
        int lastArrow = points[0][1];
        
        for(int i=1;i<size;++i)
        {
            if(lastArrow<points[i][0])
            {
                ++arrows;
                lastArrow = points[i][1];
            }
            else
            lastArrow = min(lastArrow, points[i][1]); 
                
        }
        return arrows;
    }
};