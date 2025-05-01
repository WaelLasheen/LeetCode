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
    vector<int> res;

    void dfs(TreeNode* root ,int i){
        if(!root) return;

        if(res.size() >= i+1){
            res[i] = max(res[i],root->val);
        }else{
            res.push_back(root->val);
        }

        dfs(root->left ,i+1);
        dfs(root->right ,i+1);
    }

    vector<int> largestValues(TreeNode* root) {
        dfs(root ,0);
        return res;
    }
};