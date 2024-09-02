#define ll long long
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int s=chalk.size();
        ll sum = accumulate(chalk.begin(),chalk.end() ,0LL);

        k %=sum;

        for(int i=0;i<s;i++){
            if(chalk[i] > k){
                return i;
            }
            k -=chalk[i];
        }

        return s-1; // no need to this
    }
};