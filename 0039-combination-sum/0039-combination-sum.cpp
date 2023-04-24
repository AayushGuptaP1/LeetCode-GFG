class Solution {
private:
    void uniqueSet(vector<int> &candidates,int index,int target,vector<int> &ans,vector<vector<int>> &res)
    {
        if(target==0)
        {
            res.push_back(ans);
            
            return;
        }
        if(target<0 || index == candidates.size())
            return;
        
        
        ans.push_back(candidates[index]);
        uniqueSet(candidates,index,target-candidates[index],ans,res);
        
        ans.pop_back();
        uniqueSet(candidates,index+1,target,ans,res);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        
        vector<vector<int>> res;
        vector<int> ans;
        uniqueSet(candidates,0,target,ans,res);
        
        
        return res;
    }
};