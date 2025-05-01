class Solution {
public:
    void intersectionInPlace(std::vector<int>& vec1, std::vector<int>& vec2) {
        std::sort(vec1.begin(), vec1.end());
        std::sort(vec2.begin(), vec2.end());
        
        int i = 0, j = 0, k = 0;
        
        while (i < vec1.size() && j < vec2.size()) {
            if (vec1[i] < vec2[j]) {
                i++;
            } else if (vec2[j] < vec1[i]) {
                j++;
            } else {
                vec1[k++] = vec1[i];
                i++;
                j++;
            }
        }
        
        vec1.resize(k);
    }

    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size() ,n=matrix[0].size();
        vector<int> mr(m,INT_MAX) ,mc(n,INT_MIN);       // min in rows and max in colums
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mr[i]=min(mr[i],matrix[i][j]);
                mc[j]=max(mc[j],matrix[i][j]);
            }
        }
        // answer is intersection between max in colums and min in rows
        intersectionInPlace(mr,mc);
        return mr;
    }
};
