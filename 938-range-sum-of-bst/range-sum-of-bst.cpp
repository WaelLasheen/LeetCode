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
    int sum=0;
    void bst(TreeNode* root, int l, int h){
        if(!root){
            return;
        }

        int v=root->val;
        if(v>=l && v<= h){
            sum +=v;
        }
        
        if(v>l) bst(root->left,l,h);
        if(v<h) bst(root->right,l,h);

    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        bst(root,low,high);

        return sum;
    }
};