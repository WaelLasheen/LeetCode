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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty()){
            return NULL;
        }

        int r= postorder.back();
        TreeNode* root = new TreeNode(r);
        int m=find(inorder.begin(),inorder.end(),r) - inorder.begin();

        vector<int> inSubL(inorder.begin() ,inorder.begin()+m);
        vector<int> inSubR(inorder.begin()+m+1 ,inorder.end());

        vector<int> postSubL(postorder.begin() ,postorder.begin()+m);
        vector<int> postSubR(postorder.begin()+m ,postorder.end()-1);

        root->left = buildTree(inSubL,postSubL);
        root->right = buildTree(inSubR,postSubR);

        return root;
    }
};