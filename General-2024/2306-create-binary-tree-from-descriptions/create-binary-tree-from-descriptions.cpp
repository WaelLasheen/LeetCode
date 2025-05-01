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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int s = descriptions.size();
        unordered_map<int,TreeNode*> nodes;
        set<int> p ,c;      // parent and child to decate root
        for(vector<int> node:descriptions){
            // if parent node not exict creat it
            if(!nodes[node[0]]){
                nodes[node[0]] = new TreeNode(node[0]);
            }
            // if child node not exict creat it
            if(!nodes[node[1]]){
                nodes[node[1]] = new TreeNode(node[1]);
            }
            // now let's conect each nodes
            if(node[2]){
                nodes[node[0]]-> left = nodes[node[1]];
            }else{
                nodes[node[0]]-> right = nodes[node[1]];
            }

            p.insert(node[0]);
            c.insert(node[1]);
        }

        std::set<int> r;
        std::set_difference(p.begin(), p.end(), c.begin(), c.end(),std::inserter(r, r.begin()));

        return nodes[*(r.begin())];

    }
};