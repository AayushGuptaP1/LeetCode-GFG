class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        int n = triangle.size();
        vector<int> curr(begin(triangle[n-1]),end(triangle[n-1]));
        
        for(int i=n-2;i>=0;--i)
        {
            for(int j=0;j<=i;++j)
            {
                curr[j] = min(curr[j],curr[j+1]) + triangle[i][j];
            }
        }
        return curr[0];
    }
};