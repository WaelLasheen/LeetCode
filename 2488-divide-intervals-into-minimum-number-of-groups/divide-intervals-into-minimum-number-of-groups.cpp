class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int ml=0;
        for(vector<int> i:intervals){
            ml=max(ml,i[1]);
        }
        vector<int> pref(ml+2,0);

        for(vector<int> i:intervals){
            pref[i[0]]++;
            pref[i[1]+1]--;
        }

        int res=0;
        for(int i=1;i<ml+2;i++){
            pref[i]+= pref[i-1];
            res=max(res,pref[i]);
        }
        
        return res;
    }
};