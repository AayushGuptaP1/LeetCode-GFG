class Solution {
public:
    int maximum69Number (int num) 
    {
        int n = 0;        
        while(num>0)
        {
             n = n*10 + num%10;
            num /= 10;            
        }
        num = n;
        n=0;        
        int count = 0;
        
        while(num > 0)
        {
            int x =  num%10;
            
            if(x == 6 && count == 0)
            {
                x = 9;
                count++;
            }
            n = n*10 + x;
            num /= 10;
        }
        return n;
    }
};