class Solution {
public:
    bool strongPasswordCheckerII(string password) 
    {
        int n = password.length();
        if(n<8)return false;
        bool lower = false, upper = false, digit = false, special = false;
   int count = 0;
   
   for(int i = 0;i<n; ++i)
   {
       if(i<n-1 && password[i] == password[i+1])
           return false;
       if(password[i]>='A' && password[i]<='Z')
       upper = true;
       else if (password[i]>='a' && password[i]<='z')
       lower = true;
       else if(password[i]>='0' && password[i]<= '9')
       digit = true;
       else
       special = true;
   }
   return(lower&&upper&&digit&&special);
   

   

    }
};