class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l=0, r=0 ,it=0;
        vector<int> res(m+n);
        while(it<m+n){
            if(l>=m){
                res[it]=nums2[r++];
            }
            else if(r>=n){
                res[it]=nums1[l++];
            }
            else if(nums1[l]<nums2[r]){
                res[it]=nums1[l++];
            }
            else{
                res[it]=nums2[r++];
            }
            it++;
        }

        nums1=res;
    }
};