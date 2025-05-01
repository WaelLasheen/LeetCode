class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int,int> frt ,fra;
        for(int i:target) frt[i]++;
        for(int i:arr) fra[i]++;

        return frt==fra;
    }
};