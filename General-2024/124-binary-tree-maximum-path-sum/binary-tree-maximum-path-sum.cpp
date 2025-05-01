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
    int maxpath=INT_MIN;
    int value(TreeNode* r,int v,int mv){
        if(!r) return mv;
        v +=r->val;
        mv=max(mv,v);
        int lv=value(r->left ,v,mv);
        int rv=value(r->right ,v,mv);
        return max({lv,rv});
    }

    void dfs(TreeNode* r){
        if(!r) return;
        // the min value to node is -1000
        // -1000<  node value <1000 
        int lv=value(r->left,0,-1000);
        int rv=value(r->right,0,-1000);
        maxpath=max({maxpath,lv+rv+r->val,r->val,lv+r->val,rv+r->val});
        dfs(r->left);
        dfs(r->right );
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxpath;
    }
};