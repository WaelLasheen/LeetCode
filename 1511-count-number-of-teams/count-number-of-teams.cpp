class Solution {
public:
    int numTeams(vector<int>& rating) {
        int s = rating.size();
        vector<int> maxc(s,0) ,minc(s,0);
        for(int i=0;i<s;i++){
            for(int j=i+1;j<s;j++){
                rating[j] > rating[i]? maxc[i]++:minc[i]++;
            }
        }
        int c=0;
        for(int i=0;i<s;i++){
            for(int j=i+1;j<s;j++){
                if(rating[j] > rating[i]){
                    c +=min(maxc[i],maxc[j]);
                }else{
                    c += min(minc[i],minc[j]);
                }
            }
        }

        return c;

    }
};