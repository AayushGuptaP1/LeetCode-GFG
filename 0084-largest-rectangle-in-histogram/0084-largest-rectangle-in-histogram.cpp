class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {  
        
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        
        for(int i=0; i<n; ++i)
        {
            while(st.empty() == false && heights[st.top()]>= heights[i])
            {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty()? i : i-st.top()-1;
                maxArea = max(maxArea, height*width);
                
            }
            st.push(i);
        }
        while(st.empty() == false)
        {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty()? n : n-st.top()-1;
            maxArea = max(maxArea, height*width);
            
        }
        return maxArea;        
        
    }
};