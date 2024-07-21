class Solution {
public:
    vector<vector<string>> res;

    bool isPal(string& s){
        int l=s.size();
        for(int i=0;i<=l/2;i++){
            if(s[i] != s[l-1-i]){
                return false;
            }
        }
        return true;
    }

    void dfs(string& s ,int start,vector<string>& curr){
        if(start >= s.size()){
            res.push_back(curr);
            return;
        }

        for(int i=start;i<s.size();i++){
            string sub = s.substr(start,i-start+1);
            if(isPal(sub)){
                curr.push_back(sub);
                dfs(s,i+1,curr);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> curr;
        dfs(s,0,curr);
        return res;
    }
};
