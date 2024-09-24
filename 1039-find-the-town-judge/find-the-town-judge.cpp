class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1) return 1;
        map<int,int> fr ,t;
        for(auto i:trust){
            fr[i[1]]++;
            t [i[0]]++;
        }

        for(auto i:fr){
            if(i.second == n-1 && !t[i.first]){
                return i.first;
            }
        }

        return -1;
    }
};
