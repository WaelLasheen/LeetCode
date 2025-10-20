class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res=0;
        for(string s:operations){
            s[1]=='+'? res++:res--;
        }

        return res;
    }
};