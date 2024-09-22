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
    void dfs(TreeNode* r ,vector<int>& l){
        if(!r->left && !r->right){
            l.push_back(r->val);
            return;
        }
        if(r->left) dfs(r->left ,l);
        if(r->right) dfs(r->right ,l);

    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> l1,l2;
        dfs(root1 ,l1);
        dfs(root2 ,l2);
        return l1==l2;
    }
};