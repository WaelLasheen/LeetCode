class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int len = nums.size();
        vector<int> lPref(len,nums[0]) ,rPref(len,nums.back());
        for(int l=1 ,r=len-2; l<len; l++,r--){
            lPref[l] = lPref[l-1]+ nums[l];
            rPref[r] = rPref[r+1]+ nums[r];
        }

        if(rPref[0] < x) return -1;

        int res= getCount(lPref,x);
        for(int i=len-1,t=1; i>-1; i--,t++){
            if(rPref[i] >x) break;
            if(rPref[i] == x){
                res = (res==-1? t:min(res,t));
            }

            int temp = getCount(lPref,x-rPref[i]);
            if(temp !=-1){
                if(res ==-1){
                    res = temp+t;
                } else{
                    res = min(res, temp+t);
                }
            }
        }

        return res;
    }

private:
    int getCount(const vector<int>& arr, int target) {
        auto it = lower_bound(arr.begin(), arr.end(), target);

        if (it == arr.end() || *it != target) {
            return -1;
        }

        return it - arr.begin()+1;
    }
};
/*
    [1,1,4,2,3]
    [1,2,6,8,11]
    [11,10,9,5,3]

    [3,2,20,1,1,3]
    [3,5,25,26,27,30]
    [30,27,25,5,4,3]
*/