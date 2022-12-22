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
    int res;
    void smallK(TreeNode *root, int &k)
    {
        if(root == NULL)
            return;
        smallK(root->left,k);
        if(--k == 0)
        {
            res = root->val;
            return;
        }
        smallK(root->right,k);
        
    }
    
    int kthSmallest(TreeNode* root, int k) 
    {
        
        smallK(root,k);
        return res;
        
    }
};