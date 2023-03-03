//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) 
    {
        unordered_set<string> st(begin(wordList),end(wordList));
        queue<pair<string,int>> q;
        q.push({startWord,1});
        st.erase(startWord);
        
        
        
        while(!q.empty())
        {
            string word = q.front().first;
            int time = q.front().second;
            q.pop();
            
            if(word == targetWord)
            return time;;
            
            for(int i=0;i<word.size();++i)
            {
                char original = word[i];
                
                for(char c = 'a'; c<='z';++c)
                {
                    word[i] = c;
                    
                    if(st.find(word)!= st.end())
                    {
                        q.push({word,time+1});
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
           
        }
        return 0;
    }
};

//{ Driver Code Starts.
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
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends