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
    void empty(queue<TreeNode*>& q){
        queue<TreeNode*> x;
        swap(q,x);
    }

    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q,inner;
        vector<int> res;
        q.push(root);
        while(q.size()){
            int v = INT_MIN;
            while(q.size()){
                v=max(v,q.front()->val);
                if(q.front()->left){
                    inner.push(q.front()->left);
                }
                if(q.front()->right){
                    inner.push(q.front()->right);
                }
                q.pop();
            }
            res.push_back(v);
            q=inner;
            empty(inner);
            // while(inner.size()) inner.pop();
        }

        return res;
    }
};