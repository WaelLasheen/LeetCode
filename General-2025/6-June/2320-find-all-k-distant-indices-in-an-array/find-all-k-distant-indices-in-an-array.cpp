class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int it=0 ,s=nums.size();
        vector<int> res;
        for(int i=0;i<s;i++){
            if(nums[i]==key){
                for(int j=it=max(it,i-k) ;j<min(i+k+1,s) ;j++ ,it++){
                    res.push_back(j);
                }
            }
        }


        return res;
    }
};