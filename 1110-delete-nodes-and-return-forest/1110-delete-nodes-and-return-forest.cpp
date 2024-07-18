
class Solution {
private:
    TreeNode* findForest(TreeNode *root, vector<TreeNode*>&res, unordered_set<int>&st)
    {
        if(root == nullptr)
            return root;
        root->left = findForest(root->left,res,st);
        root->right = findForest(root->right,res,st);
        
        if(st.find(root->val) != st.end())
        {
            if(root->left)
                res.push_back(root->left);
            if(root->right)
                res.push_back(root->right);
            delete root;
            return root = nullptr;
        }
        return root;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& del) 
    {
        vector<TreeNode*> res;
        unordered_set<int> st(begin(del),end(del));
        root = findForest(root,res,st);
        if(root)
            res.push_back(root);
        return res;               
    }
};