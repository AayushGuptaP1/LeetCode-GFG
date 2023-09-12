class Solution {

    
public:
    int uniquePaths(int m, int n) 
    {
//         Combinatorial Solution
//         int N = m+n-2;
//         int R = m-1;
//         double res =1;
        
//         for(int i =1;i<=R;++i)
//         {
//             res = res*(N-R+i)/i;
//         }
//         return (int)res; 
        
        vector<int> pre(n,1);
        
        for(int i=1;i<m;++i)
        {
            for(int j=1;j<n;++j)
            {
                pre[j] +=pre[j-1];
            }
            
        }
        return pre[n-1];
        
        
        
             
    }
};