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
    void helper(TreeNode *root, int &sum, int &localSum)
    {
        if(root==NULL)
            return;
        
        localSum = (localSum*10)+root->val;
        
        if(root->left == NULL && root->right == NULL)
        {
            sum += localSum;
            localSum /= 10; 
            return;
        }
        
        helper(root->left,sum,localSum);
        helper(root->right,sum,localSum);
        localSum /= 10;
        
        
    }
public:
    int sumNumbers(TreeNode* root) 
    {
        int sum = 0;
        int localSum = 0;
        helper(root,sum,localSum);
        return sum;
        
    }
};