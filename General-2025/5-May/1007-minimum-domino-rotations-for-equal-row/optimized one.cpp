class Solution {
public:
    int checkRotations(int target, vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size(), topRot = 0, botRot = 0;
        for (int i = 0; i < n; ++i) {
            if (tops[i] != target && bottoms[i] != target) return n + 1;
            topRot += tops[i] != target;
            botRot += bottoms[i] != target;
        }
        return min(topRot, botRot);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int rotations = min(checkRotations(tops[0], tops, bottoms), checkRotations(bottoms[0], tops, bottoms));
        return rotations > n ? -1 : rotations;
    }
};