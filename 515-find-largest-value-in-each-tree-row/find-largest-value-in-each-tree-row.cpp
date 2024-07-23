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
    map<int,int> mir;   // max in row

    void dfs(TreeNode* root ,int i){
        if(!root) return;

        if(mir.find(i) != mir.end()){
            mir[i] = max(mir[i],root->val);
        }else{
            mir[i]=root->val;
        }

        dfs(root->left ,i+1);
        dfs(root->right ,i+1);
    }

    vector<int> largestValues(TreeNode* root) {
        dfs(root ,0);
        vector<int> res(mir.size());
        for(auto n:mir) res[n.first] = n.second;
        return res;
    }
};