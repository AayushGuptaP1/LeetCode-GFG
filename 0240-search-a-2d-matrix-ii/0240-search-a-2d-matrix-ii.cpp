class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int i=matrix.size()-1;
        int j = 0;
        int n = matrix[0].size()-1;
        
       
        
        while(i>=0 && j<=n)
        {
            if(matrix[i][j] == target)
                return true;
            else if(target < matrix[i][j])
                i--;
            else
                j++;
        }
        return false;         
    }
};