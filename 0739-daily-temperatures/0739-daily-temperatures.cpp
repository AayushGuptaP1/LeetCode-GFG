class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        
        int n = temperatures.size();
        vector<int> res(n);
        stack<int>st;
        
        for(int i = n-1; i>=0; --i)
        {
            while(st.empty() == false && temperatures[st.top()]<= temperatures[i])
                st.pop();
            
            res[i] = st.empty()? 0 : st.top()-i;
            st.push(i);
        }
        return res;
        
        
    }
};