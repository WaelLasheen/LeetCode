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
    int diameter = 0;

    int solve(TreeNode* root) {
        if (!root) return 0;

        int leftDepth = solve(root->left);
        int rightDepth = solve(root->right);

        // Update the diameter at each node
        diameter = max(diameter, leftDepth + rightDepth);

        // Return the depth of the current subtree
        return max(leftDepth, rightDepth) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return diameter;
    }
};
