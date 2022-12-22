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
    int maxLevelSum(TreeNode* root) 
    {
        map<int,int>mp;
        queue<TreeNode*>nodes;
        int level = 1;
        int res, maxi = INT_MIN;
        nodes.push(root);
        while(nodes.empty()==false)
        {
            int size = nodes.size();
            
            for(int i=0;i<size;++i)
            {
                TreeNode *temp = nodes.front();
                nodes.pop();
                mp[level] += temp->val;
                if(temp->left)
                    nodes.push(temp->left);
                if(temp->right)
                    nodes.push(temp->right);
            }
            level++;            
        }
        
        for(auto &x : mp)
        {
            if(x.second>maxi)
            {
                maxi = x.second;
                res = x.first;
            }
        }
        return res;
    }
};