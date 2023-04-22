class Solution {
private:
    void generateSum(int sum,int index,int k,int n,vector<int> &seq, vector<vector<int>> &res)
    {
        if(sum>n || k<0)
            return;
        if(sum == n && k== 0)
        {
            res.push_back(seq);
            return;
        }
        for(int i=index;i<=9;++i)
        {
            seq.push_back(i);
            generateSum(sum+i,i+1,k-1,n,seq,res);
            seq.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> res;
        vector<int> seq;
        
        
        generateSum(0,1,k,n,seq,res);
        return res;
        
    }
};