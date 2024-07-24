class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        map<int,vector<int>> newNums;
        int s =nums.size();
        // int p=0;
        for(int i:nums){
            int x=0 ,n=i;
            // if num is from one digit we do it away
            if(n<10){
                newNums[mapping[n]].push_back(i);
                // nums[p]=x;
                // p++;
                continue;
            }
            string num= to_string(i);
            for(char c:num){
                x = x*10+mapping[(c-'0')];
                n /=10;
            }

            newNums[x].push_back(i);
            // nums[p]=x;
            // p++;
        }
        int p=0;
        for(auto i:newNums){
            for(int x:i.second){
                nums[p]=x;
                p++;
            }
        }
        return nums;
    }
};