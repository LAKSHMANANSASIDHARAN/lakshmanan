/*1380. Lucky Numbers in a Matrix
Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.
A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.
Example 1:

Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 2:

Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 3:

Input: matrix = [[7,8],[1,2]]
Output: [7]
Explanation: 7 is the only lucky number since it is the minimum in its row and the maximum in its column.*/
class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> res;

for (int i = 0; i < matrix.size(); i++) {
    int min_val = INT_MAX, col_idx = -1;

    for (int j = 0; j < matrix[0].size(); j++) {
        if (matrix[i][j] < min_val) {
            min_val = matrix[i][j];
            col_idx = j;
        }
    }

    
    bool is_lucky = true;
    for (int k = 0; k < matrix.size(); k++) {
        if (matrix[k][col_idx] > min_val) {
            is_lucky = false;
            break;
        }
    }

    if (is_lucky)
        res.push_back(min_val);
}

return res;
    }
};
