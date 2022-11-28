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
    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        vector<vector<int>>res;
        if(root == NULL)
            return res;
        queue<pair<TreeNode*,pair<int,int>>>q;
        map<int,map<int,multiset<int>>> nodes;
        
        q.push({root,{0,0}});
        
        while(q.empty()==false)
        {
            auto it = q.front();
            q.pop();
            TreeNode *temp = it.first;
            int x = it.second.first;
            int y = it.second.second;
            
            nodes[x][y].insert(temp->val);
            
            if(temp->left != NULL)
                q.push({temp->left,{x-1,y+1}});
            if(temp->right != NULL)
                q.push({temp->right,{x+1,y+1}});
        }
        
        for(auto x : nodes)
        {
            vector<int>col;
            for(auto y : x.second)
                col.insert(col.end(),y.second.begin(),y.second.end());
            res.push_back(col);
        }
        return res;
    }
};