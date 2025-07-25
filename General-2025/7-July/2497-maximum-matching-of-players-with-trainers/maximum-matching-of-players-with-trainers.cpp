class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int p1=0 ,p2=0 ,res=0;
        while(p1<players.size() && p2<trainers.size()){
            if(trainers[p2] >= players[p1]){
                p1++;
                res++;
            }
            p2++;
        }

        return res;
    }
};