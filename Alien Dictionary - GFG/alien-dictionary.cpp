//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) 
    {
        vector<vector<int>> graph(K);
        vector<int> dep(K,0);
        queue<int>q;
        string res = "";
        
        for(int i=0;i<N-1;++i)
        {
            int j=0,k=0;
            while(j<dict[i].size() && k<dict[i+1].size())
            {
                if(((i==0 && j==0)||(dict[i][j-1]==dict[i+1][k-1]))&&(dict[i][j]!=dict[i+1][k]))
                {
                    graph[dict[i][j]-'a'].push_back(dict[i+1][k]-'a');
                    dep[dict[i+1][k]-'a']++;
                    j++,k++;
                    break;
                }
                j++,k++;
            }
        }
        
        for(int i=0;i<K;++i)
        {
            if(dep[i]==0)
            q.push(i);
        }
        
        while(q.empty()==false)
        {
            int z = q.front();
            q.pop();
            res = res+char(z+'a');
            
            for(auto &x : graph[z])
            {
                dep[x]--;
                if(dep[x]==0)
                q.push(x);
            }
        }
        return res;
        
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends