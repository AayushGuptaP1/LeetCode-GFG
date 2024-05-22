class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) 
    {
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        int count = 0;
        unordered_set<int> st;
        
        for(auto &x : nums)
        {
            for(auto &p : primes)
            {
                if(x%p == 0)
                {
                    st.insert(p);
                    while(x%p == 0)
                        x /= p;
                }
            }
            if(x!= 1)
                st.insert(x);
        }
        return st.size();
        
        
        
        
    }
};