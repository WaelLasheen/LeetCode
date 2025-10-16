class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int mx= nums.size()+1;
        map<int,int> mp;

        for(int i:nums){
            i = (i%value + value)%value;
            mp[i]++;
        }

        for(int i=0;i<mx;i++){
            if(!mp[i%value]){
                return i;
            }
            mp[i%value]--;
        }
        return -1;
    }
};