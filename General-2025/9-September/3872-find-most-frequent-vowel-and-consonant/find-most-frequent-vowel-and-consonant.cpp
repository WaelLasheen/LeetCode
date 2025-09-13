class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> mp;
        int f1=0 ,f2=0;
        for(char i:s){
            mp[i]++;
            if(i=='a' || i=='e' ||i=='o' ||i=='i' ||i=='u'){
                f1=max(f1 ,mp[i]);
            } else{
                f2=max(f2 ,mp[i]);
            }
        }

        return f1+f2;
    }
};