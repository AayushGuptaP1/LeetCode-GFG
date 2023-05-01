class Solution {
public:
    double average(vector<int>& salary)
    {
        int n = salary.size();
        int mini = salary[0], maxi = salary[0];
        int sum = 0;
        
        for(int i=0;i<n;++i)
        {
            mini = min(mini,salary[i]);
            maxi = max(maxi,salary[i]);
            sum += salary[i];
        }
        double result = (sum-mini-maxi)/(n-2.0);
        return result;
    }
};