class Solution {
public:
    bool judgeSquareSum(int c) 
    {
        long int low = 0, high = sqrt(c);
        
        
        while(low <= high)
        {
            long int res = low*low + high*high;
            
            if(res == c)
                return true;
            else if(res < c)
                low++;
            else
                high--;
        }
        return false;        
    }
};