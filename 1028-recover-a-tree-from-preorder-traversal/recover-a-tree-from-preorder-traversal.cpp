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
    TreeNode* recoverFromPreorder(string traversal) {
        vector<pair<int,int>> arr;  // level, node value
        long l=0 ,it=0 ,curr=0;
        while(it<traversal.size()){
            if(traversal[it] !='-'){
                curr = curr*10 + (traversal[it]-'0');
            } else{
                if(curr){
                    arr.push_back({l,curr});
                    curr=0;
                    l=1;
                }
                else{
                    l++;
                }
            }

            it++;
        }
        // don't forget to add last value
        arr.push_back({l,curr});
        TreeNode* root = new TreeNode(arr[0].second);
        map<int,TreeNode*> mp;  // last used level : node
        mp[0]=root;
        for(int i=1;i<arr.size();i++){
            int parentLevel = arr[i].first-1;
            TreeNode* node = new TreeNode(arr[i].second);
            mp[arr[i].first] = node;

            if(!mp[parentLevel]->left){
                mp[parentLevel]->left = node;
            }
            else{
                mp[parentLevel]->right = node;
            }
        }
        
        return root;
    }
};