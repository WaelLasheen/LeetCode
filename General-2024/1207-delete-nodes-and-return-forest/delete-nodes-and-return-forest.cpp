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
    vector<TreeNode*> forest;

    void dfs(TreeNode*& root, vector<int>& d){
        if(!root) return;
        dfs(root->left,d);
        dfs(root->right,d);
        if(find(d.begin(),d.end(),root->val) != d.end()){
            if(root->left) forest.push_back(root->left);
            if(root->right) forest.push_back(root->right);
            delete root;
            root=nullptr;
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        dfs(root,to_delete);
        if(root)forest.push_back(root);
        return forest;
    }
};