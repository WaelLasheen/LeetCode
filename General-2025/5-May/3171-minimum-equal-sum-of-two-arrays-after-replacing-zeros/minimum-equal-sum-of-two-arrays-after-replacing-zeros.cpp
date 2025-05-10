#define ll long long
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        ll s1= 0 ,s2=0;
        int z1=0 ,z2=0;

        for(int i:nums1){
            if(!i){
                z1++;
            }
            s1 +=i;
        }
        for(int i:nums2){
            if(!i){
                z2++;
            }
            s2 +=i;
        }

        if(z1 && z2) return max(s1+z1 ,s2+z2);
        if(z1 && !z2 && s1+z1 <= s2) return s2;
        if(z2 && !z1 && s2+z2 <= s1) return s1;
        if(!z1 && !z2 && s1 == s2) return s1;

        return -1;
    }
};