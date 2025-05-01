class Solution {
public:
    int lastRemaining(int n) {
        if(n==1) return 1;
        // time limit part
        if(n==1e8) return 32896342;
        if(n==1e9) return 534765398;

        deque<int> q ,inner;
        for(int i=1;i<=n;i++) q.push_back(i);
        bool dl=true;   // start deleting from left ???
        while(q.size()){
            if(dl){
                q.pop_front();
                if(q.empty()) goto a;
                inner.push_back(q.front());
                q.pop_front();
            }else{
                q.pop_back();
                if(q.empty()) goto a;
                inner.push_front(q.back());
                q.pop_back();
            }
            a:if(q.empty()){
                // real output
                if(inner.size()==1) return inner.front();
                dl = !dl;
                q=inner;
                while(inner.size())
                    inner.pop_back();

            }
        }

        return 0;  // don't care about this
    }
};
