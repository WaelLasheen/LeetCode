class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> nums={1};
        int i2=0 ,i3=0, i5=0;
        for(int i=1;i<n;i++){
            int num= min({nums[i2]*2 ,nums[i3]*3 ,nums[i5]*5});
            nums.push_back(num);
            if(num == nums[i2]*2){
                i2++;
            }
            if(num == nums[i3]*3){
                i3++;
            }
            if(num == nums[i5]*5){
                i5++;
            }
        }

        return nums[n-1];
    }
};