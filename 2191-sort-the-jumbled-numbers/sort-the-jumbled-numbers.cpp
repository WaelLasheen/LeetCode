class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        multimap<int,int> newNums;
        int s =nums.size();
        for(int i:nums){
            int x=0;
            // if num is from one digit we do it away
            if(i<10){
                newNums.insert(pair<int,int>(mapping[i],i));
                continue;
            }
            string num= to_string(i);
            for(char c:num){
                x = x*10+mapping[(c-'0')];
            }

            newNums.insert(pair<int,int>(x,i));
        }
        int p=0;
        for(auto i:newNums){
            nums[p]=i.second;
            p++;
        }
        return nums;
    }
};