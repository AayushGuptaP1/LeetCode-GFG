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
public:
    int pathSum(TreeNode *root, int &res)
    {
        if(root==NULL)
            return 0;
        int l = max(0,pathSum(root->left,res));
        int r = max(0,pathSum(root->right,res));
        res = max(root->val+l+r,res);
        return max(l,r)+root->val;
        
    }
    int maxPathSum(TreeNode* root)
    {
        int res = root->val;
        pathSum(root,res);
        return res;
    }
};