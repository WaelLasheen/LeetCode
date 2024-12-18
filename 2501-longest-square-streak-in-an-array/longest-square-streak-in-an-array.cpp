class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        map<int,int> mp;
        for(int i:nums) mp[i]++;
        int res=-1;
        for(int i:nums){
            long n=i;
            int len=0;
            while(mp[n] && n<= nums.back()){
                n*=n;
                len++;
            }
            if(len >1){
                res=max(res,len);
            }
        }

        return res;
    }
};