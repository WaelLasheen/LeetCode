class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int s=nums.size() , c=0;
        sort(nums.begin(),nums.end());
        for(int i=s-1;i>=2;i--){
            int l=0 , r=i-1;     // [a,.....,b,c] 
            while(l<r){
                if(nums[l]+nums[r]>nums[i]){  // if sum of less num and pre last greater than max value so any num between then will achieve this condition
                    c +=(r-l);
                    r--;
                }
                else
                    l++;
            }
        }
        return c;
    }
};