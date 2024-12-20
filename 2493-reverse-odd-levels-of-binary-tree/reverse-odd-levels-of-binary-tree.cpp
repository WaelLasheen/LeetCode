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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root || !root->left) return root;

        queue<TreeNode*> q;
        q.push(root);
        bool odd=true;
        while(q.size()){
            int k=q.size();
            stack<int> s;
            queue<TreeNode*> oddq;
            while(k--){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                    q.push(curr->right);
                    if(odd){
                        s.push(curr->left->val);
                        s.push(curr->right->val);
                        oddq.push(curr->left);
                        oddq.push(curr->right);
                    }
                }
            }
            
            while(s.size()){
                oddq.front()->val = s.top();
                oddq.pop();
                s.pop();
            }
            odd = !odd;
        }

        return root;
    }
};