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
    bool sym=true;
    void dfs(TreeNode*l ,TreeNode*r){
        if(!r && !l) return;
        if(!r || !l || r->val != l->val){
            sym=false;
            return;
        }
        
        dfs(r->left, l->right);
        dfs(l->left, r->right);
        
    }
    bool isSymmetric(TreeNode* root) {
        // you can pass root if you want
        // dfs(root,root)
        // but no need to check root as it common
        
        dfs(root->left ,root->right);
        return sym;
    }
};