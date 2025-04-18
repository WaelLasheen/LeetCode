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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<ll> level;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            int len=q.size();
            ll sum=0;
            while(len--){
                TreeNode* node=q.front();
                q.pop();
                sum +=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            level.push_back(sum);
        }
        
        sort(level.rbegin(),level.rend());

        return k>level.size()? -1:level[k-1];
    }
};
