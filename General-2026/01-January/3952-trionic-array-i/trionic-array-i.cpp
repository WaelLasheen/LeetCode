class Solution {
public:
    int interval(vector<int>& nums ,int it ,int sgn){
        int s= nums.size();
        for(int i=it+1;i<s;i++){
            if(sgn*nums[i] > sgn*nums[i-1]){
                it++;
            } else{
                break;
            }
        }
        return it;
    }

    bool isTrionic(vector<int>& nums) {
        int s= nums.size();
        int p = interval(nums,0,1);
        int q = interval(nums,p,-1);
        int l = interval(nums,q,1);

        return p && q !=p && l ==s-1 && l !=q;
    }
};