class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int>res;
        for(int i:spells){
            double val=success/(1.0*i);
            int s= potions.end() - lower_bound(potions.begin(), potions.end(), val);
            res.push_back(s);
        }
        return res;
    }
};