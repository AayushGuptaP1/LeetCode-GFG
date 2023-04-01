class Solution {
private:
    void generate(string s, vector<string> &ans, int left, int right)
    {
        if(left == 0 && right == 0)
        {
            ans.push_back(s);
            return;
        }
        if(left>0){ generate(s+"(",ans,left-1,right);}
        if(right>left){generate(s+")",ans,left,right-1);}
    }
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;
        
        
        generate("",ans,n,n);
        return ans;
    }
};