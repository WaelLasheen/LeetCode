class Solution {
public:
    int getxor(vector<int>& nums){
        int res=0;
        for(int i:nums) res ^=i;
        return res;
    }

    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int s1=nums1.size() ,s2=nums2.size();
        if(!(s1&1) && !(s2&1)) return 0;
        if(!(s1&1)) return getxor(nums1);
        if(!(s2&1)) return getxor(nums2);
        return getxor(nums1)^getxor(nums2);
    }
};