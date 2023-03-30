class Solution {
private:
    void powerSet(vector<int>&nums,int index,vector<int> &current, vector<vector<int>> &ans)
    {
        ans.push_back(current);                 
        for(int i=index;i<nums.size();++i)
        {
            if(i==index || nums[i] != nums[i-1])
            {
                current.push_back(nums[i]);
                powerSet(nums,i+1,current,ans);
                current.pop_back();
            }
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        sort(begin(nums),end(nums));
        vector<int> current;
        vector<vector<int>> ans;
        powerSet(nums,0,current,ans);
        return ans;  
    }
};