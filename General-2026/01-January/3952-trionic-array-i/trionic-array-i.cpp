class Solution {
public:
    int interval(vector<int>& nums ,int it){
        int s= nums.size();
        for(int i=it+1;i<s;i++){
            if(nums[i]>nums[i-1]){
                it++;
            } else{
                break;
            }
        }
        return it;
    }

    bool isTrionic(vector<int>& nums) {
        int s= nums.size();
        int p = interval(nums,0);

        int q=p;
        for(int i=p+1;i<s;i++){
            if(nums[i] < nums[i-1]){
                q++;
            } else{
                break;
            }
        }
        int l = interval(nums,q);

        return p && q !=p && l ==s-1 && l !=q;
    }
};