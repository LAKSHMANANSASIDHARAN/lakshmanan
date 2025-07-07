/*867. Transpose Matrix

Given a 2D integer array matrix, return the transpose of matrix.

The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.



 

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]
Example 2:

Input: matrix = [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]*/
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
       vector<vector<int>>ans;
    for(int i=0;i<matrix[0].size();i++){
            vector<int>temp;
       for(int j=0;j<matrix.size() ;j++) 
           {
            temp. push_back(matrix[j][i]);
           }
            ans.push_back(temp);
        }
        return ans;
    }
}