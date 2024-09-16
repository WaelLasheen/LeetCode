class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(),timePoints.end());
        int s =timePoints.size();
        vector<int> t(s);
        for(int i=0;i<s;i++){
            int h= stoi(timePoints[i].substr(0,2))*60;
            int m= stoi(timePoints[i].substr(3,2));
            t[i]=h+m;
        }
        int res=min(t[s-1]-t[0] ,24*60-(t[s-1]-t[0]));
        // if res is 0 no need to continue
        if(!res) return res;

        for(int i=1;i<s;i++){
            res = min(res ,t[i]-t[i-1]);
            // if res is 0 no need to continue
            if(!res) return res;
        }

        return res;
    }
};