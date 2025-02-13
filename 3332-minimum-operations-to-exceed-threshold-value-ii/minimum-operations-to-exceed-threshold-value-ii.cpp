#define ll long long

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        int cnt=0;
        for(ll i:nums){
            pq.push(i);
        }

        while(pq.size()>1 && pq.top()<k){
            ll x=pq.top();  // min
            pq.pop();
            ll y=pq.top();  // max
            pq.pop();
            ll add = 2*x +y;
            pq.push(add);
            cnt++;
        }

        return cnt;
    }
};