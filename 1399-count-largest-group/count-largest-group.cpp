class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> mp;
        int mx=0 ,res=0;
        for(int i=1;i<=n;i++){
            int s= ++mp[digits_sum(i)];
            mx=max(mx,s);
        }

        for(auto [_,i]:mp){
            if(i==mx){
                res++;
            }
        }

        return res;
    }

private:
    int digits_sum(int n){
        int sum=0;
        while(n){
            sum +=n%10;
            n /=10;
        }

        return sum;
    }
};