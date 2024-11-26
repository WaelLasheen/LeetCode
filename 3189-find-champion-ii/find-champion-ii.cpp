// nice solution from neetcode
// https://youtu.be/HjSmSLPR7S4?si=fZFwIOOZmD9TRGxd

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> income(n,0);
        for(vector<int> e:edges){
            income[e[1]]++;
        }

        vector<int> champions;
        
        for(int i=0;i<n;i++){
            if(income[i]==0){
                champions.push_back(i);
            }
        }

        return champions.size() >1 ? -1 : champions[0];
    }
};