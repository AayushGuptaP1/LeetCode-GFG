class Solution {
private:
    void permutation(int i, string &s, vector<string>&ans)
    {
        if(i == s.length())
        {
            ans.push_back(s);
            return;
        }
        if(s[i]< '0' || s[i]>'9')
        {
            permutation(i+1,s,ans);
        
        if(s[i]>=65 && s[i]<=90)
            s[i] += 32;
        else if(s[i]>= 97 && s[i]<=122)
            s[i] -= 32;
            
        }
        
        
        permutation(i+1,s,ans);
    }
public:
    vector<string> letterCasePermutation(string s)
    {
        vector<string> ans;
        permutation(0,s,ans);
        return ans;
        
        
    }
};