class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int,int> mp;
        int s=nums.size() ,res=0;
        for(int i=0;i<s;i++){
            for(int j=i+1;j<s;j++){
                int n= nums[i] * nums[j];
                mp[n]++;
            }
        }

        for(auto i:mp){
            int n=i.second;
            // the hard part of code
            res += 4*((n)*(n-1));
        }

        return res;
    }
};