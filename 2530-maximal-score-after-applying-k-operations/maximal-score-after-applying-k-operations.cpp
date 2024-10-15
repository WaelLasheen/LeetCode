#define ll long long
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        ll res=0;
        priority_queue<int> pq;
        for(int i:nums){
            pq.push(i);
        }
        while(k--){
            int n=pq.top();
            pq.pop();
            res += 1ll*n;
            n=(n+2)/3;  // same ceil function
            pq.push(n);
        }

        return res;
    }
};