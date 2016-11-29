class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int finalV = A.size();
        int finalH = B[0].size();
        vector<vector<int> > result (finalV, vector<int> (finalH));
        
        for (int row = 0; row < finalV; row++) {
            vector<int>& curA = A[row];
            vector<int>& curRes = result[row];
            for (int i = 0; i < curA.size(); i++) {
                if (curA[i] == 0) {
                    continue;
                }
                for (int j = 0; j < B.size(); j++) {
                    curRes[j] += curA[i] * B[i][j];
                }
            }
        }
        
        return result;
    }
};