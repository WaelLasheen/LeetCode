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
    bool res=true;
    void dfs(TreeNode* root1, TreeNode* root2){
        if(!res) return;
        if(!root1 && !root2) return;
        if(!root1 && root2 || root1 && !root2){
            res=false;
            return;
        }
        if(root1->left && root1->right && root2->left && root2->right){
            if(root1->left->val == root2->left->val && root1->right->val == root2->right->val){
                dfs(root1->left,root2->left);
                dfs(root1->right,root2->right);
            }
            else if(root1->right->val == root2->left->val && root1->left->val == root2->right->val){
                dfs(root1->left,root2->right);
                dfs(root1->right,root2->left);
            }
            else{
                res=false;
                return;
            }
        }
        else if(!root1->left && root1->right && !root2->left && root2->right){
            if(root1->right->val == root2->right->val){
                dfs(root1->right,root2->right);
            }
            else{
                res=false;
                return;
            }
        }
        else if(!root1->left && root1->right && root2->left && !root2->right){
            if(root1->right->val == root2->left->val){
                dfs(root1->right,root2->left);
            }
            else{
                res=false;
                return;
            }
        }
        else if(root1->left && !root1->right && root2->left && !root2->right){
            if(root1->left->val == root2->left->val){
                dfs(root1->left,root2->left);
            }
            else{
                res=false;
                return;
            }
        }
        else if(root1->left && !root1->right && !root2->left && root2->right){
            if(root1->left->val == root2->right->val){
                dfs(root1->left,root2->right);
            }
            else{
                res=false;
                return;
            }
        }
        else if(!root1->left && !root1->right && !root2->left && !root2->right){
            return;
        }
        else{
            res=false;
            return;
        }
        
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return true;
        if(!root1 && root2 || root1 && !root2) return false;
        if(root1->val != root2->val) return false;
        dfs(root1,root2);
        return res;
    }
};