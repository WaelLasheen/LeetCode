class Solution {
public:
    double average(vector<int>& salary) {
        double ans=0;
        int s=salary.size() ,maxn=salary[0] ,minn=maxn;
        for(int i:salary){
            ans +=i;
            minn=min(minn,i);
            maxn=max(maxn,i);
        }
        return (ans-minn-maxn)/((s-2)*1.0);
    }
};