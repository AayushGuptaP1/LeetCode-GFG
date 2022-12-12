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
    bool checkBST(TreeNode *root,long low,long high)
    {
        if(root == NULL)
            return true;
        if(root->val >= high || root->val <= low)
            return false;
        return(checkBST(root->left,low,root->val) && checkBST(root->right,root->val,high));
    }
    
public:
    bool isValidBST(TreeNode* root)
    {
       return checkBST(root,LONG_MIN,LONG_MAX);        
    }
};