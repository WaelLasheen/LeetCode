class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool isThereAnyOdd = false;
        sort(nums1.begin(),nums1.end());
        for(int i=0;i<nums1.size();i++){
            if(((nums1[i]&1) != (nums1[0]&1) )&& !isThereAnyOdd){
                return false;
            }
            if(nums1[i]&1)  isThereAnyOdd= true;
        }

        return true;
    }
};