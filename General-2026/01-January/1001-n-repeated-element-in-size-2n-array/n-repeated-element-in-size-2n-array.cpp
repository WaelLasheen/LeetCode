class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,bool> appear;
        for(int i:nums){
            if(appear[i]){
                return i;
            }
            appear[i] = true;
        }

        return -1;
    }
};