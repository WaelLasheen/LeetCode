class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());

        int res=0;
        int p1=g.size()-1 ,p2=s.size()-1;
        while(p1>-1 && p2 >-1){
            if(s[p2] >= g[p1]){
                res++;
                p2--;
            }
            p1--;
        }

        return res;
    }
};