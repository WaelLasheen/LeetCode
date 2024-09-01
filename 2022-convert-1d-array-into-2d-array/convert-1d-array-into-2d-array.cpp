class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int s=original.size();
        if(n*m != s) return {};
        vector<vector<int>> res;
        for(int i=0;i<s;i +=n){
            vector<int> sub(original.begin()+i ,original.begin()+i+n);
            res.push_back(sub);
        }

        return res;
    }
};