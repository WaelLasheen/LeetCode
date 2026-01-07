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

 #define ll long long

class Solution {
public:
    ll res=0;
    const int mod = 1e9+7;

    int prefix(TreeNode* root){
        int l=0 ,r=0;
        if(root->left){
            l = prefix(root->left);
        }
        if(root->right){
            r = prefix(root->right);
        }

        root->val += l+r;
        return root->val;
    }
    
    void dfs(TreeNode* root ,int total){
        if(root->left){
            int l = root->left->val;
            res= max(res ,1LL * (total - l) *l);
            dfs(root->left,total);
        }
        if(root->right){
            int r = root->right->val;
            res= max(res ,1LL *(total - r) * r);
            dfs(root->right,total);
        }
    }

    int maxProduct(TreeNode* root) {
        int total = prefix(root);
        dfs(root,total);
        return res%mod;
    }
};