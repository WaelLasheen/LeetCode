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
    void dfs(TreeNode* root, int v, vector<int>& n, string& p, bool& found) {
        if (!root || found) return; // If root is null or the target is found, return
        n.push_back(root->val);
        if (root->val == v) {
            found = true;
            return;
        }
        p += 'L';
        dfs(root->left, v, n, p, found);
        if (found) return; // If the target is found in the left subtree, return
        p.pop_back();
        
        p += 'R';
        dfs(root->right, v, n, p, found);
        if (found) return; // If the target is found in the right subtree, return
        p.pop_back();
        
        n.pop_back();
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        vector<int> ns, nd;
        string ps = "", pd = "";
        bool found = false;
        
        dfs(root, startValue, ns, ps, found);
        found = false;
        dfs(root, destValue, nd, pd, found);

        // Find the lowest common ancestor
        int i = 0;
        while (i < ns.size() && i < nd.size() && ns[i] == nd[i]) {
            i++;
        }
        i--; // move back to the last common node

        // Build the path from the startValue to the lowest common ancestor
        string ans = "";
        for (int u = i + 1; u < ns.size(); u++) {
            ans += 'U';
        }

        // Append the path from the lowest common ancestor to the destValue
        for (int p = i; p < pd.size(); p++) {
            ans += pd[p];
        }

        return ans;
    }
};
