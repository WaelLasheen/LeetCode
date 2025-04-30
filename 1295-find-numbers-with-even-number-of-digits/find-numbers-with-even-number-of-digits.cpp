class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res=0;
        for(int i:nums){
            res += isEven(i);
        }

        return res;
    }
private:
    bool isEven(int n){
        int cnt=0;
        while(n){
            n /=10;
            cnt++;
        }

        return !(cnt&1);
    }
};