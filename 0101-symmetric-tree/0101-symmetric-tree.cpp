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
    bool isSymmetric(TreeNode* root) 
    {
        if(root == NULL)
            return true;
        return checkSymmetry(root->left,root->right);
    }
    
    bool checkSymmetry(TreeNode *l, TreeNode *r)
    {
        if(l== NULL && r==NULL)
            return true;
         else if (l!= NULL && r!= NULL)
            return (l->val == r->val) && checkSymmetry(l->left,r->right) && checkSymmetry(l->right,r->left);
        else
            return false;
        
        
    }
};