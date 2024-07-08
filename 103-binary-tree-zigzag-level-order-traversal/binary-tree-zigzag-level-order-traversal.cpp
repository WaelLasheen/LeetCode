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
    map<int,vector<int>> level;
    void dfs(TreeNode* r,int l){
        if(!r) return;
        level[l].push_back(r->val);
        dfs(r->left,l+1);
        dfs(r->right,l+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        dfs(root,0);
        vector<vector<int>> res;
        bool rev=false;
        for(auto i:level){
            if(rev){
                reverse(i.second.begin(),i.second.end());
            }
            res.push_back(i.second);
            rev =!rev;
        }
        return res;
    }
};