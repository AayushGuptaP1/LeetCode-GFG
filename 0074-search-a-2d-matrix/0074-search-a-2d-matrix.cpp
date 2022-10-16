class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int low=0;
        int high = (matrix[0].size()*matrix.size())-1;
        int n = matrix[0].size() ;
                
        while(low<=high)
        {
           int mid = (low+high)/2;
            
            if(matrix[mid/n][mid%n] == target)
                return true;
            else if(matrix[mid/n][mid%n] > target)
                high = mid-1;
            else
                low = mid+1;
        }
        return false;
    }
};