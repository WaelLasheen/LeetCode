class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int doub=0;
        int s=nums.size() ,sum = ((1+s)*s)/2;
        sort(nums.begin(),nums.end());
        for(int i=0;i<s;i++){
            if(i && nums[i] == nums[i-1]){
                doub=nums[i];
            }
            sum -= nums[i];
        }

        return {doub ,doub+sum};
    }
};