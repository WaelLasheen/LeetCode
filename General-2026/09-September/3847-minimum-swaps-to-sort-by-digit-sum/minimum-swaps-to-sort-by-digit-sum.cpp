class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end(), [&](int a, int b) {
            int sumA = digitSum(a);
            int sumB = digitSum(b);

            if (sumA != sumB) {
                return sumA < sumB;
            }
            return a < b;
        });

        unordered_map<int,int> mp;
        int len= nums.size();
        for(int i=0;i<len;i++){
            mp[nums[i]]=i;
        }

        int res=0;
        for(int i=0;i<len;i++){
            if(temp[i] != nums[i]){
                int idx = mp[temp[i]];
                
                mp[nums[i]] = idx;
                mp[temp[i]] = i;
                
                swap(nums[i], nums[idx]);
                res++;
            }
        }

        return res;
    }

private:
    int digitSum(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
};