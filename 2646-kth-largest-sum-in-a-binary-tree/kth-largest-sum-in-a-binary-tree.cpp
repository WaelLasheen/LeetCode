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
    vector<ll> level;
    void DFS(TreeNode* root ,int i){
        if(!root){
            return;
        }
        if(i>= level.size()){
            level.push_back(root->val);
        }
        else{
            level[i] +=root->val;
        }
        DFS(root->left,i+1);
        DFS(root->right,i+1);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        DFS(root,0);
        sort(level.rbegin(),level.rend());

        return k>level.size()? -1:level[k-1];
    }
};