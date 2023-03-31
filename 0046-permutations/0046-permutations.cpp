class Solution {
private:
    void generatePermutations(vector<int> &nums,int index,vector<vector<int>> &ans)
    {
        if(index==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();++i)
        {
            swap(nums[index],nums[i]);
            generatePermutations(nums,index+1,ans);
            swap(nums[i],nums[index]);            
        }
       
    }
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        
        vector<vector<int>> res;
        generatePermutations(nums,0,res);
        return res;
        
    }
};