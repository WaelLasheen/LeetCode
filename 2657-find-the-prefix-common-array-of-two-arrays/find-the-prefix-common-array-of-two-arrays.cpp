class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int s=A.size();
        vector<bool> nums(s,false);
        vector<int> res(s,0);

        for(int i=0;i<s;i++){
            int mp=0;
            nums[B[i]-1] = true;

            for(int j=0;j<=i;j++){
                mp += nums[A[j]-1];
            }

            res[i]=mp;
        }
        return res;
    }
};