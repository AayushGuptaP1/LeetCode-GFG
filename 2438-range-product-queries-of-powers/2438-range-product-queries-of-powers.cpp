class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) 
    {
        const unsigned int M = 1000000007;
        

        int count = 1;
        vector<int> v;
        vector<int> power(queries.size(),1);
        
        while(n)
        {
            if((n & 1) == 1)
                v.push_back(count);
            count *= 2;
            n = n>>1;
        }
        
        
        for(int i = 0; i<queries.size();i++)
        {
            long long temp = 1;
            for(int j = queries[i][0]; j<= queries[i][1];j++)
            {
               temp = ((temp%M)*v[j])%M;                 
            }
            power[i] = temp;
        }
        return power;
    }
};