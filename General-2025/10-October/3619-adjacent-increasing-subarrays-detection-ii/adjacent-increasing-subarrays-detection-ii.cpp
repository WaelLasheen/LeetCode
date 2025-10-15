class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        vector<int> fr;
        int c=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i] > nums[i-1]) c++;
            else{
                fr.push_back(c);
                c=1;
            }
        }
        fr.push_back(c);
        int res=1;
        for(int i=0;i<fr.size();i++){
            res= max(res,fr[i]/2);
            if(i+1<fr.size()){
                res=max(res,min(fr[i],fr[i+1]));
            }
        }

        return res;
    }
};