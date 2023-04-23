//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    bool wordSearch(vector<vector<char>> &board, string word,int index, int i,int j)
    {
        if(index == word.length())
            return true;
        if(i<0 || i>= board.size() || j<0 || j>=board[0].size() || board[i][j] != word[index]  )
            return false;
        
        char c = board[i][j];
        board[i][j] = '#';
        
        bool res = (wordSearch(board,word,index+1,i-1,j)||wordSearch(board,word,index+1,i+1,j)||wordSearch(board,word,index+1,i,j-1)||wordSearch(board,word,index+1,i,j+1));
        
        board[i][j] = c;
        return res;
    }
public:
    bool isWordExist(vector<vector<char>>& board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        
        
        
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(board[i][j] == word[0])
                {
                    if(wordSearch(board,word,0,i,j))
                        return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends