#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int l=0 ,r=0 ,mni=-1 ,mxi=-1;
        ll res=0;
        while(r<nums.size()){
            if(nums[r]< minK || nums[r]> maxK){
                l=r+1;
                mni=mxi=-1;
            }
            else{
                if(nums[r]==minK){
                    mni=r;
                }
                if(nums[r]==maxK){
                    mxi=r;
                }

                if(mni !=-1 && mxi !=-1){
                    res += min(mni,mxi)-l+1;
                }
            }
            r++;
        }

        return res;
    }
};