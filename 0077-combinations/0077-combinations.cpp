class Solution {
private:
    void generateCombinations(int n, int num,int k, vector<int> &combination, vector<vector<int>> &ans)
    {
      if(combination.size() == k)
      {
          ans.push_back(combination);
          return;
      }
        
        for(int i=num;i<=n;++i)
        {
                combination.push_back(i);
                generateCombinations(n,i+1,k,combination,ans);
                combination.pop_back();   
        }
        
    }
public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> ans;
        vector<int> combination;
        generateCombinations(n,1,k,combination,ans);
        return ans;
    }
};