class Solution {
public:
    bool isval(int a,int b,int c){
        return a+b>c && b+c>a && a+c>b;
    }

    int largestPerimeter(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        for(int i=0;i<nums.size()-2;i++){
            if(isval(nums[i],nums[i+1],nums[i+2])){
                return nums[i]+nums[i+1]+nums[i+2];
            }
        }
        return 0;
    }
};