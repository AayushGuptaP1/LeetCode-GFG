/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void generatePath(TreeNode *root, int targetSum, vector<int> &path, vector<vector<int>> &res)
    {
        if(root == NULL)
            return;
        
        path.push_back(root->val);
        
        if(root->left == NULL && root->right == NULL && targetSum == root->val)
            res.push_back(path);
        
        generatePath(root->left,targetSum - root->val,path,res);
        generatePath(root->right,targetSum - root->val,path,res);
        path.pop_back();
        
        
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        vector<vector<int>> res;
        vector<int> path;
        generatePath(root,targetSum,path,res);
        return res;      
        
    }
};