/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    void traverse(Node *root, vector<int>&res)
    {
        if(root == nullptr)
            return;
        for(auto &x : root->children)
        {
            traverse(x,res);
        }
        res.push_back(root->val);
        
    }
public:
    vector<int> postorder(Node* root)
    {
        vector<int> ans;
        traverse(root,ans);
        return ans;
        
        
    }
};