class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) 
    {
        int n = arr.size();
        vector<int> dp(n,1), hash(n);
        sort(begin(arr),end(arr));
        int len = 1,lastIndex = 0;
        
        for(int index=0;index<n;++index)
        {
            hash[index] = index;
            for(int prev = 0; prev<index;++prev)
            {
                if(arr[index] % arr[prev] == 0 && dp[prev]+1 > dp[index])
                {
                    dp[index] = dp[prev]+1;
                    hash[index] = prev;
                }
            }
            if(dp[index]> len)
            {
                len = dp[index];
                lastIndex = index;
            }
        }
        vector<int> res(len);
        int index = len-1;
        
        while(hash[lastIndex] != lastIndex)
        {
            res[index--] = arr[lastIndex];
            lastIndex = hash[lastIndex];
        }
        res[0] = arr[lastIndex];
        return res;
    }
};