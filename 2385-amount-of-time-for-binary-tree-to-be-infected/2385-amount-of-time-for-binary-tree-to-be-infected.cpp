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
    void buildGraph(TreeNode* root, unordered_map<int,vector<int>> &mp)
    {
        if(root == nullptr)
        return;
        buildGraph(root->left,mp);
        if(root->left)
        {
            mp[root->val].push_back(root->left->val);
            mp[root->left->val].push_back(root->val);
        }
        if(root->right)
        {
            mp[root->val].push_back(root->right->val);
            mp[root->right->val].push_back(root->val);
            
        }
        buildGraph(root->right,mp);
        
    }
public:
    int amountOfTime(TreeNode* root, int target) 
    {
        unordered_map<int,vector<int>> mp;
        buildGraph(root,mp);
        unordered_set<int> visited;
        int level = -1;
        
        queue<int> q;
        q.push(target);
        visited.insert(target);
        while(!q.empty())
        {
            int size = q.size();
            level++;
            
            for(int i=0;i<size;++i)
            {
                int node = q.front();
                q.pop();
                for(auto &x : mp[node])
                {
                    if(visited.find(x)== visited.end())
                    {
                        visited.insert(x);
                        q.push(x);
                    }
                }
            }
            
        }
        return level;        
    }
};