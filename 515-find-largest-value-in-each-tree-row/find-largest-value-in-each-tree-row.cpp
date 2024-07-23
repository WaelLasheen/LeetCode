/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x, left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x, left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        
        queue<TreeNode*> q;
        vector<int> res;
        
        q.push(root);
        while (!q.empty()) {
            int v = INT_MIN;
            int size = q.size(); // Get the current level size
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                v = max(v, node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(v);
        }

        return res;
    }
};
