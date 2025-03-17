/*Flip Columns For Maximum Number of Equal Rows
You are given an m x n binary matrix matrix.
You can choose any number of columns in the matrix and flip every cell in that column (i.e., Change the value of the cell from 0 to 1 or vice versa).
Return the maximum number of rows that have all values equal after some number of flips.
Example 1:
Input: matrix = [[0,1],[1,1]]
Output: 1
Explanation: After flipping no values, 1 row has all values equal.
Example 2:
Input: matrix = [[0,1],[1,0]]
Output: 2
Explanation: After flipping values in the first column, both rows have equal values.
Example 3:
Input: matrix = [[0,0,0],[0,0,1],[1,1,0]]
Output: 2
Explanation: After flipping values in the first two columns, the last two rows have equal values.*/
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> mpp;
        for (int i = 0; i < matrix.size(); i++) {
            string s = "", t = "";
            for (int j = 0; j < matrix[0].size(); j++) {
                s += to_string(matrix[i][j]);
                t += to_string(1 - matrix[i][j]);  
            }
            mpp[s]++;
            mpp[t]++;
        }

        int maxCount = 0;
        for (auto& [key, val] : mpp) {
            maxCount = max(maxCount, val);
        }

        return maxCount;
    }
};
