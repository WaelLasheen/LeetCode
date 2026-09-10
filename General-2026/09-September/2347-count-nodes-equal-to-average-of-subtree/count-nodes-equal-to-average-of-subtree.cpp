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
    map<TreeNode*,vector<int>> mp; // node: [subtree_sum,n]

    int averageOfSubtree(TreeNode* root) {
        int l=0 ,r=0;
        if(root->left) l= averageOfSubtree(root->left);
        if(root->right) r= averageOfSubtree(root->right);
        mp[root] = {root->val,1};
        if(root->left){ 
            mp[root][0] += mp[root->left][0];
            mp[root][1] += mp[root->left][1];
        }
        if(root->right){
            mp[root][0] += mp[root->right][0];
            mp[root][1] += mp[root->right][1];
        }
        int avg = mp[root][0]/mp[root][1];
        return l+r + (avg == root->val);
    }
};