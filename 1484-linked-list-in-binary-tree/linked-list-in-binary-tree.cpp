/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool res = false;
    void solve(TreeNode* root ,ListNode* it ,bool is_equal){
        if(!it && is_equal){
            res = true;
        }

        if(!it || !root || res || root->val != it->val){
            return;
        }

        solve(root->left ,it->next ,root->val == it->val && is_equal);
        solve(root->right ,it->next ,root->val == it->val && is_equal);
    }

    void dfs(TreeNode* root ,ListNode* it){
        if(!root || res){
            return;
        }

        solve(root ,it ,root->val == it->val);
        dfs(root->left ,it);
        dfs(root->right ,it);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        dfs(root ,head);
        return res;
    }
};