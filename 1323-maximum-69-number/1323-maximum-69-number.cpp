class Solution {
public:
    int maximum69Number (int num) 
    {
        int max6 = -1;
        int n = num;
        int i = 1;
        
        while(n>0)
        {
        
            if(n%10 == 6)
                max6 = i;
            i*= 10;
            n/= 10;                
        }
        return max6==-1? num: num+ 3*max6;
    }
};