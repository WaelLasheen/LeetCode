class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>arr;
        for(int i:nums1)arr.push_back(i);
        for(int i:nums2)arr.push_back(i);
        sort(arr.begin(),arr.end());
        int s=arr.size();
        return s%2? arr[s/2]:(arr[s/2-1]+arr[s/2])/2.0;
    }
};