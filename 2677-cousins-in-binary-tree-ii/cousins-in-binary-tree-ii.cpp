#define ll long long
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
    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val=0;
        queue<TreeNode*> pre,curr;
        pre.push(root);
        if(root->left) curr.push(root->left);
        if(root->right) curr.push(root->right);
        while(curr.size()){
            int len1=pre.size() ,len2= curr.size();
            ll sum=0;
            while(len2--){
                TreeNode* node=curr.front();
                curr.pop();
                sum +=node->val;
                if(node->left) curr.push(node->left);
                if(node->right) curr.push(node->right);
                pre.push(node);
            }

            while(len1--){
                ll sub=0;
                TreeNode* node=pre.front();
                pre.pop();
                if(node->left) sub +=node->left->val;
                if(node->right) sub +=node->right->val;

                if(node->left) node->left->val = sum-sub;
                if(node->right) node->right->val = sum-sub;
            }
        }

        return root;
    }
};