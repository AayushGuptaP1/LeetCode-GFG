class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>> matrix(n,vector<int>(n));
        int top = 0, right = n-1;
        int left = 0 , bottom = n-1;
        int count = 1;
        
         
        
        while(top<=bottom && left<=right)
        {
            for(int i = left; i <= right; ++i)
            {
                matrix[top][i] = count;
                ++count;
            }               
            ++top;
            
            for(int i = top;i <= bottom; ++i)
            {
                matrix[i][right] = count;
                ++count; 
            } 
            --right;
            
            if(top<=bottom)
            {
                for(int i = right;i >= left; --i)
                {
                    matrix[bottom][i] = count;
                    ++count;                     
                }
                --bottom;
                        
            }
            if(left<=right)
            {
                for(int i = bottom;i>=top; --i)
                {
                    matrix[i][left]= count;
                    ++count;                                      
                }
                ++left;     
            }                    
        }
        return matrix; 
    }
};