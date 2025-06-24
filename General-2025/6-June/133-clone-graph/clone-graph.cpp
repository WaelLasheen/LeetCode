/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return node;
        }
        unordered_map<int,Node*> mp;    // visited
        queue<Node*> q;
        q.push(node);
        mp[node->val] = new Node(node->val);

        while(q.size()){
            Node* curr=q.front();
            q.pop();

            for(Node* n:curr->neighbors){
                if(!mp.count(n->val)){
                    mp[n->val]= new Node(n->val);
                    q.push(n);
                }
                mp[curr->val]->neighbors.push_back(mp[n->val]);
            }
        }

        return mp[node->val];
    }
};