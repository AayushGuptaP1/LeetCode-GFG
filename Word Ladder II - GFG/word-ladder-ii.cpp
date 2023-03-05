//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> st(begin(wordList),end(wordList));
        vector<vector<string>> ans;
        unordered_set<string> used;
        bool lastLevel = false;
        queue<vector<string>> q;
        q.push({beginWord});
        
        while(q.empty() == false)
        {
            int size = q.size();
             
            for(int i=0;i<size;++i)
            {
                vector<string> seq = q.front();
                q.pop();
                string last = seq.back();
                if(last == endWord)
                {
                    
                    ans.push_back(seq);
                }
                
                
                
                for(int j=0;j<last.size();++j)
                {
                    char original = last[j];
                    for(char c= 'a';c<='z';++c)
                    {
                        last[j] = c;
                        if(last == endWord)
                            lastLevel = true;
                        
                        if(st.find(last)!=st.end())
                        {
                            seq.push_back(last);
                            used.insert(last);
                            q.push(seq);
                            seq.pop_back();    
                        }
                    }
                    last[j] = original;
                }
                
            }
            
            for(auto &c : used)
                st.erase(c);
            
            
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends