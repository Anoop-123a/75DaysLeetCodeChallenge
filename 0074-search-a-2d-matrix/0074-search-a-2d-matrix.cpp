// 75 Leetcodechallenge-->>

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();    // No of rows
        int n = matrix[0].size(); // No of columns
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (matrix[row][col] == target) {
                    return true;
                }
            }
        }

        return false;
    }
};