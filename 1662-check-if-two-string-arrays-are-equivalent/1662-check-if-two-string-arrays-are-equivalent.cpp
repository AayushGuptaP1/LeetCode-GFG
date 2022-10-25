class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
    {
        string s1 = " ";
        string s2 = " ";
        for(string c : word1)
            s1 += c;
        
        for(string c : word2)
            s2 += c;
        
        return (s1==s2);
    }
};