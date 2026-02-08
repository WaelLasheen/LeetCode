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
bool res = true;
    bool isBalanced(TreeNode* root) {
        depth(root);
        return res;
    }

private:
    int depth(TreeNode* root){
        if(!root || !res) return 0;
        int l = depth(root->left) +1;
        int r = depth(root->right) +1;
        if(abs(r-l) > 1) res=false;
        return max(l,r);
    }
};