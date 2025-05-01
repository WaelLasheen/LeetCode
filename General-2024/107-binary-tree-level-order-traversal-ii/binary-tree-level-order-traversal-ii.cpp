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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        while(q.size()){
            TreeNode* curr=q.front().first;
            int l= q.front().second;
            q.pop();
            if(res.size()<l){
                res.push_back({curr->val});
            } else{
                res[l-1].push_back(curr->val);
            }

            if(curr->left){
                q.push({curr->left ,l+1});
            }
            if(curr->right){
                q.push({curr->right ,l+1});
            }
        }

        reverse(res.begin(),res.end());

        return res;
    }
};