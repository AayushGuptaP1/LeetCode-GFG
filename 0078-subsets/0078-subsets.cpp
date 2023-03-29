class Solution {
private :
    void subSetGenerate(vector<int> &nums, int index, vector<vector<int>> & res,vector<int> &set)
    {
        if(index == nums.size())
        {
            res.push_back(set);
            return;
        }
        set.push_back(nums[index]);
        subSetGenerate(nums,index+1,res,set);
        set.pop_back();
        subSetGenerate(nums,index+1,res,set);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> res;
        vector<int> set;
        subSetGenerate(nums,0,res,set);
        return res;
        
    }
};