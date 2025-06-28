class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq ,pq2;
        vector<int> res(k);
        int it=k-1;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i] ,i});
        }

        while(k--){
            auto [val,i] = pq.top();
            pq.pop();
            pq2.push({i,val});
        }

        while(pq2.size()){
            res[it--] = pq2.top().second;
            pq2.pop();
        }

        return res;
    }
};