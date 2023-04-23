class Solution {
private:
    void generatingSubsequences(vector<int> &nums, int index, vector<int> &seq, set<vector<int>> &res)
    {
        if(index == nums.size())
        {
            if( seq.size()>=2)
            res.insert(seq);
            return;
        }
        
        
        if(seq.empty() || seq.back()<= nums[index])
        {
            seq.push_back(nums[index]);
            generatingSubsequences(nums,index+1,seq,res);
            seq.pop_back();
        }
        
        generatingSubsequences(nums,index+1,seq,res);
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums)
    {
        vector<int> seq;
        set<vector<int>> res;
        generatingSubsequences(nums,0,seq,res);
        return vector(res.begin(),res.end());
    }
};