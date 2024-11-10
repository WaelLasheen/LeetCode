class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> bits(32,0);
        int s = nums.size();
        int l=0 ,r=0 ,res=s+1;
        while(r<s){
            if(nums[r] >=k) return 1;

            int n=nums[r],it=0;
            while(n){
                bits[it++] +=n&1;
                n >>=1;
            }
            for(int i=0;i<32;i++){
                if(bits[i]){
                    n += 1<<i;
                }
            }
            while(n >= k){
                res = min(res,r-l+1);
                it=0;
                while(nums[l]){
                    bits[it++] -=nums[l]&1;
                    nums[l] >>=1;
                }
                n=0;
                for(int i=0;i<32;i++){
                    if(bits[i]){
                        n += 1<<i;
                    }
                }
                l++;
            }

            r++;
        }

        return res==s+1?-1:res;
    }
};