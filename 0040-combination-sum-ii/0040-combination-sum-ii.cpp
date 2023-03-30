class Solution {
private:
    void findCombinations(vector<int> &candidates,int index,int target,vector<int> &current,vector<vector<int>> &ans)
    {
        if(target<0)
            return;
        if(target==0)
        {
            ans.push_back(current);
            return;
        }
        
        for(int i=index;i<candidates.size();++i)
        {
            if(i == index || candidates[i]!=candidates[i-1])
            {
                current.push_back(candidates[i]);
                findCombinations(candidates,i+1,target-candidates[i],current,ans);
                current.pop_back();
            }
            
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(begin(candidates),end(candidates));
        vector<vector<int>> ans;
        vector<int> current;
        
        findCombinations(candidates,0,target,current,ans);
        return ans;
    }
};