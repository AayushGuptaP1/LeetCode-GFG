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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        
        queue<TreeNode*>q;
        q.push(root);
        bool reverse = false;
        
        while(q.empty()==false)
        {
            int size = q.size();
            vector<int>ans(size);
            
            for(int i=0;i<size;++i)
            {
                TreeNode *curr = q.front();
                q.pop();
                
                int index = reverse? size-i-1:i;
                ans[index] = curr->val;
                if(curr->left != NULL)
                    q.push(curr->left);
                if(curr->right != NULL)
                    q.push(curr->right);                
            }
            reverse = !reverse;
            res.push_back(ans);
        }
        return res;
        
    }
};