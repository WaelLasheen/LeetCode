class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int res=0 ,s=dominoes.size();
        map<vector<int> ,int> fr;
        for(int i=0;i<s;i++){
            sort(dominoes[i].begin(),dominoes[i].end());
            fr[dominoes[i]]++;
        }
        for(auto i:fr){
            int n=i.second;
            res += (n*(n-1))/2;
        }

        return res;
    }
};