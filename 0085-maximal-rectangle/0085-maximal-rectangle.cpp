class Solution {
public:
    
    int maxHistogram(vector<int> histogram, int n)
    {
        int maxArea = 0;
        stack<int> st;
        
        for(int i=0;i<n;i++)
        {
            while(st.empty() == false && histogram[st.top()]>= histogram[i])
            {
                int height = histogram[st.top()];
                st.pop();
                int width = st.empty()? i : i-st.top()-1;
                maxArea = max(maxArea, height*width);
            }
            st.push(i);
        }
        while(st.empty() == false)
        {
            int height = histogram[st.top()];
            st.pop();
            int width = st.empty()? n : n-st.top()-1;
            maxArea = max(maxArea, height*width);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int n = matrix[0].size();
        int m = matrix.size();
        vector<int> histogram(n,0);
        int maxA = 0;
        
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(matrix[i][j] == '1')
                    histogram[j]++;
                else
                    histogram[j] = 0;
            }
            maxA = max(maxA, maxHistogram(histogram,n));
            
            
        }
        return maxA;
        
        
    }
};