class Solution {
public:
    vector<long long> sumOfThree(long long num) 
    {
        if(num%3==0)
        {
            long long n = num/3;
            return{n-1,n,n+1};
        }
        return{};            
    }
};