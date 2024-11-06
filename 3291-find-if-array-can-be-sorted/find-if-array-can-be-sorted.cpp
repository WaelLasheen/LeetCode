class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int s=nums.size();
        vector<int> bits(s,0);
        for(int i=0;i<s;i++){
            int n=nums[i];
            while(n){
                bits[i] += n&1;
                n >>=1;
            }
        }
        vector<int> arr(nums.begin(),nums.end());
        int l=0,r=0;
        while(r<s){
            while(r<s && bits[r]==bits[l]) r++;
            sort(arr.begin()+l ,arr.begin()+r);
            l=r;
        }

        sort(nums.begin(),nums.end());
        return nums==arr;
    }
};