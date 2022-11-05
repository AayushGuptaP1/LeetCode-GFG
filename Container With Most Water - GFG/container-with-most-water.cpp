//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long height[], int len)
{
    long long maxArea = 0;
        long long i=0, j = len-1;
        
        while(i<j)
        {
            if(height[i]<height[j])
            {
                maxArea = max(maxArea,height[i]*(j-i));
                i++;
            }
            else
            {
                maxArea = max(maxArea,height[j]*(j-i));
                j--;
            }
        }
        return maxArea;
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends