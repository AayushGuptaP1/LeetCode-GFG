//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int maxHistogram(vector<int> &histogram, int size)
    {
        int maxAr = 0;
        stack<int>st;
        
        for(int i=0;i<size;i++)
        {
            while(st.empty()== false && histogram[st.top()]>= histogram[i])
            {
                int height = histogram[st.top()];
                st.pop();
                int width = st.empty()? i : i-st.top()-1;
                maxAr = max(maxAr, height*width);
            }
            st.push(i);
        }
        while(st.empty() == false)
        {
            int height = histogram[st.top()];
            st.pop();
            int width = st.empty()? size : size-st.top()-1;
            maxAr = max(maxAr, height*width);
        }
        return maxAr;
    }
    int maxArea(int M[MAX][MAX], int n, int m) 
    {
        vector<int> histogram(m,0);
        int maxA = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(M[i][j] == 1)
                histogram[j]++;
                else
                histogram[j]=0;
            }
            maxA = max(maxA, maxHistogram(histogram,m));
            
            
        }
        return maxA;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends