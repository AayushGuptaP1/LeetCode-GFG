class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int res = INT_MAX;
        
        vector<int>curr(m,0), prev(m,0);
        
        // for(int i=0;i<m;++i)
        //     prev[i] = matrix[0][i];       
        
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<m;++j)
            {
                int leftD = (j>0)? prev[j-1] : INT_MAX;
                int rightD = (j<m-1)? prev[j+1] : INT_MAX;
                curr[j] = min(prev[j],min(leftD,rightD)) + matrix[i][j];               
            }  
            prev = curr;
        }
        
        for(int i=0;i<m;++i)
            res = min(res, prev[i]);        
        
        return res;
        
        
        
    }
};