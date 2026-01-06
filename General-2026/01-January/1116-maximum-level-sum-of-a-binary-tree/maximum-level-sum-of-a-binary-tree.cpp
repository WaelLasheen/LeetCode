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
    int maxLevelSum(TreeNode* root) {
        queue<pair<int,TreeNode*>> q;
        int res = 0 ,mx = INT_MIN ,sum=0 ,l=1;
        q.push({1,root});
        while(q.size()){
            int level = q.front().first;
            TreeNode* node = q.front().second;
            q.pop();
            if(level == l){
                sum += node->val;
            } 
            else{
                if(sum > mx){
                    mx=sum;
                    res = level-1;
                }
                l=level;
                sum = node->val;
            }
            if(node->left){
                q.push({level+1 ,node->left});
            }
            if(node->right){
                q.push({level+1 ,node->right});
            }
        }

        if(sum > mx){
            res =l;
        }

        return res;
    }
};