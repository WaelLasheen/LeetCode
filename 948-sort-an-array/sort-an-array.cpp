class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int>pq;
        for(int i:nums){
            pq.push(i);
        }
        for(int i=nums.size()-1;i>-1;i--){
            nums[i]=pq.top();
            pq.pop();
        }
        return nums;
    }
};