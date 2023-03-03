class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> st(begin(wordList),end(wordList));
        queue<pair<string,int>> q;
        
        
        q.push({beginWord,1});
        st.erase(beginWord);
        
        while(!q.empty())
        {
            string word = q.front().first;
            int time = q.front().second;
            q.pop();
            
            if(word == endWord)
                return time;
            
            for(int i=0;i<word.length();++i)
            {
                char original = word[i];
                for(int j=0;j<26;++j)
                {
                    word[i] = 'a'+j;
                    
                    if(st.find(word)!=st.end())
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