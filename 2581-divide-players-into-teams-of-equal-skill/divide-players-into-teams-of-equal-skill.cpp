# define ll long long

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int l=0 ,r=skill.size()-1;
        int val=skill[l]+skill[r];
        ll res=0;
        while(l<r){
            if(skill[l]+ skill[r] != val) return -1;
            res += (ll)skill[l] * (ll)skill[r] ;
            l++;
            r--;
        }

        return res;
    }
};