class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int it=0;
        int s1=nums1.size() ,s2=nums2.size();
        vector<int> res;
        for(int i=0;i<s1;i++){
            while(it<s2 && nums1[i]> nums2[it]) it++;
            if(it==s2) break;
            if(nums1[i]==nums2[it]){
                while(i+1<s1 && nums1[i]==nums1[i+1]) i++;
                while(it+1<s2 && nums2[it]==nums2[it+1]) it++;
                res.push_back(nums1[i]);
            }
        }

        return res;
    }
};