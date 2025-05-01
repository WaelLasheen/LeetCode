#define ll long long
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(int i:gifts){
            pq.push(i);
        }

        while(k--){
            int curr = pq.top();
            pq.pop();
            pq.push(sqrt(curr));
        }

        ll res=0;
        while(pq.size()){
            res += pq.top()*1LL;
            pq.pop();
        }

        return res;
    }
};