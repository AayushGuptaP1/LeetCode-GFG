class Solution {
private:
    void uniqueSet(vector<int> &candidates,int index,int target,vector<int> &ans, set<vector<int>> &st)
    {
        if(target<0 || index == candidates.size())
            return;
        if(target==0)
        {
            st.insert(ans);
            return;
        }
        uniqueSet(candidates,index+1,target,ans,st);
        ans.push_back(candidates[index]);
        uniqueSet(candidates,index,target-candidates[index],ans,st);
        uniqueSet(candidates,index+1,target-candidates[index],ans,st);
        ans.pop_back();
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        set<vector<int>> st;
        vector<vector<int>> res;
        vector<int> ans;
        uniqueSet(candidates,0,target,ans,st);
        
        for(auto &x : st)
        {
            res.push_back(x);
        }
        return res;
    }
};