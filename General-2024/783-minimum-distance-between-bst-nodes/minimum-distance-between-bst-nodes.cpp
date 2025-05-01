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
    vector<int> arr;
    void dfs(TreeNode* root){
        if(!root){
            return;
        }

        arr.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }

    int minDiffInBST(TreeNode* root) {
        dfs(root);
        sort(arr.begin(),arr.end());
        int res= INT_MAX;
        for(int i=0;i<arr.size()-1;i++){
            res=min(res,abs(arr[i]-arr[i+1]));
        }
        return res;
    }
};