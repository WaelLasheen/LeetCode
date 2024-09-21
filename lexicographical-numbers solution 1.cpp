class Solution {
public:
    vector<int> lexicalOrder(int n) {
        set<string> nums;
        for(int i=1;i<=n;i++){
            nums.insert(to_string(i));
        }

        vector<int> res;
        for(string i:nums){
            res.push_back(stoi(i));
        }

        return res;
    }
};
