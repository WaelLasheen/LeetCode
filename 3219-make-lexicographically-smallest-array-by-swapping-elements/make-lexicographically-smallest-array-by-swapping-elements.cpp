class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        map<int,queue<int>> mp;     // level : [element]
        unordered_map<int,int> lv;    // element: level
        vector<int> copy(nums.begin(),nums.end());
        sort(copy.begin(),copy.end());
        int level=0;
        mp[level].push(copy[0]);
        lv[copy[0]] = level;
        for(int i=1;i<nums.size();i++){
            if(copy[i]-mp[level].back() <= limit){
                mp[level].push(copy[i]);
            }else{
                level++;
                mp[level].push(copy[i]);
            }
            lv[copy[i]] = level;
        }

        for(int i=0;i<nums.size();i++){
            int curr = lv[nums[i]];     // level of current element
            nums[i]= mp[curr].front();
            mp[curr].pop();
        }

        return nums;
    }
};

/*
    limit 2
    5 1 3
    3 1 5
    1 3 5
    --------
    limit 3
    1,7,6,18,2,1
    1 1 2 | 6 7 | 18
    1 6 7 18 1 2
    -------------------
    limit 3
    1,7,28,19,10
    1 | 7 10 | 19 | 28
    1 7 28 19 10
*/