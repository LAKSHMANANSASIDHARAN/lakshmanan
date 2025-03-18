/*Rotating the Box
You are given an m x n matrix of characters boxGrid representing a side-view of a box. Each cell of the box is one of the following:
A stone '#'
A stationary obstacle '*'
Empty '.'
The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.
It is guaranteed that each stone in boxGrid rests on an obstacle, another stone, or the bottom of the box.
Return an n x m matrix representing the box after the rotation described above.
Example 1:
Input: boxGrid = [["#",".","#"]]
Output: [["."],
         ["#"],
         ["#"]]
Example 2:
Input: boxGrid = [["#",".","*","."],
              ["#","#","*","."]]
Output: [["#","."],
         ["#","#"],
         ["*","*"],
         [".","."]]
Example 3:
Input: boxGrid = [["#","#","*",".","*","."],
              ["#","#","#","*",".","."],
              ["#","#","#",".","#","."]]
Output: [[".","#","#"],
         [".","#","#"],
         ["#","#","*"],
         ["#","*","."],
         ["#",".","*"],
         ["#",".","."]]
 */
class Solution {
    void swapp(vector<char>& a) {
    int n = a.size();
    int l = n - 1, r = n - 1;  

    while (r >= 0) {
        if (a[r] == '#') {
            swap(a[r], a[l]);  
            l--;
        } else if (a[r] == '*') {
            l = r - 1;  
        }
        r--;
    }
}


public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(), n = boxGrid[0].size();
        
        for (int i = 0; i < m; i++) {
            swapp(boxGrid[i]);  
        }

        vector<vector<char>> ans(n, vector<char>(m));  

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][m - 1 - i] = boxGrid[i][j];  
            }
        }
        return ans;
    }
};
