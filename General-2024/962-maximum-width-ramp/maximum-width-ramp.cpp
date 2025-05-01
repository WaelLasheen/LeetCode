class Solution {
public:
    int lower_bound(vector<pair<int,int>>& arr ,int val){
        int l=0 ,r=arr.size()-1, ans=0;
        while(l<=r){
            int mid = l+ (r-l)/2;
            if(arr[mid].first >= val){
                ans=mid;
                r = mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return ans;
    }

    int maxWidthRamp(vector<int>& nums) {
        int s=nums.size();
        int res=0;
        vector<pair<int,int>>arr;
        arr.push_back({nums[s-1],s-1});
        for(int i=s-2;i>-1;i--){
            int l=arr.size()-1;
            if(nums[i]>arr[l].first){
                arr.push_back({nums[i],i});
            }
            else{
                int it = lower_bound(arr ,nums[i]);
                int len = arr[it].second - i;
                res=max(res,len);
            }
        }

        return res;
    }
};