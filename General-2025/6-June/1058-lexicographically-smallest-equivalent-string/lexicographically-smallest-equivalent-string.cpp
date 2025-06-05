class Solution {
public:
    int find(vector<int>& parent, int c) {
        if (parent[c] != c) parent[c] = find(parent, parent[c]);
        return parent[c];
    }
    
    void union_chars(vector<int>& parent, int c1, int c2) {
        int root1 = find(parent, c1), root2 = find(parent, c2);
        if (root1 < root2) parent[root2] = root1;
        else parent[root1] = root2;
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parent(26);
        for (int i = 0; i < 26; ++i) parent[i] = i;
        
        for (size_t i = 0; i < s1.size(); ++i) {
            union_chars(parent, s1[i] - 'a', s2[i] - 'a');
        }
        
        string result;
        for (char c : baseStr) {
            result += (char)(find(parent, c - 'a') + 'a');
        }
        
        return result;
    }
};