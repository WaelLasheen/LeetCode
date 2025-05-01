class Solution {
public:
    int minDifference(vector<int>& nums) {
        int s=nums.size();
        if(s <= 4) return 0;

        priority_queue<int> min4;
        priority_queue<int, vector<int>, greater<int>> max4;

        for (int num : nums) {
            min4.push(num);
            if (min4.size() > 4) min4.pop();

            max4.push(num);
            if (max4.size() > 4) max4.pop();
        }

        vector<int> smallest(4), largest(4);
        for (int i = 3; i >= 0; --i) {
            smallest[i] = min4.top();
            min4.pop();

            largest[3-i] = max4.top();
            max4.pop();
        }

        return min({
            largest[0] - smallest[0],
            largest[1] - smallest[1],
            largest[2] - smallest[2],
            largest[3] - smallest[3]
        });
    }
};