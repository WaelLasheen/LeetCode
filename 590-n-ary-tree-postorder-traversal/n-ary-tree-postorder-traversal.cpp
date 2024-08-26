/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> post;

    void DFS(Node* root){
        if(!root) return;

        for(Node* n: root->children){
            DFS(n);
        }
        post.push_back(root->val);
    }

    vector<int> postorder(Node* root) {
        DFS(root);
        return post;
    }
};