class Solution {
public:
    double average(vector<int>& salary) {
        double ans=0;
        int s=salary.size();
        sort(salary.begin(),salary.end());
        for(int i=1;i<s-1;i++) ans +=salary[i];
        return ans/((s-2)*1.0);
    }
};