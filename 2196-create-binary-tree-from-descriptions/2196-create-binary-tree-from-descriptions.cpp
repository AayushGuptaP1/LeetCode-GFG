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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) 
    {
        unordered_set<int> st;
        unordered_map<int,TreeNode*> mp;
        TreeNode *temp,*child;
        
        for(auto &x : descriptions)
        {
            if(mp.find(x[0]) == mp.end()) 
            {
                temp = new TreeNode(x[0]);
                mp[x[0]] = temp;                
            }                
            else
                temp = mp[x[0]];
            
            if(mp.find(x[1]) == mp.end())
            {
                child = new TreeNode(x[1]);  
                mp[x[1]] = child;
            }                
            else
                child = mp[x[1]];
                st.insert(child->val);
            if(x[2])
                temp->left = child;
            else
                temp->right = child;    
        }
        for(auto &x : mp)
        {
            if(st.find(x.second->val) == st.end())
                return x.second;
        }
        return nullptr;
        
    }
};