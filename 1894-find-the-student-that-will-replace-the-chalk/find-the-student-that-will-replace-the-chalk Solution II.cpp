class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        if(chalk.size()==1 || chalk[0]>k) return 0;

        int s=chalk.size();
        vector<long long> arr(chalk.begin(),chalk.end());
        for(int i=1;i<s;i++){
            arr[i] += arr[i-1];
            if(arr[i] > k) return i;
        }

        int ind=0;
        while(k >= 0){
            ind = upper_bound(arr.begin(),arr.end(),k)-arr.begin();
            if(ind == s){
                ind--;
            }
            k -=arr[ind];
        }

        return ind;
    }
};