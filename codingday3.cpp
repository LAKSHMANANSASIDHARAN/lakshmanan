/*2017. Grid Game - leetcode [ today's problem ]
You are given a 0-indexed 2D array grid of size 2 x n, where grid[r][c] represents the number of points at position (r, c) on the matrix. Two robots are playing a game on this matrix.
Both robots initially start at (0, 0) and want to reach (1, n-1). Each robot may only move to the right ((r, c) to (r, c + 1)) or down ((r, c) to (r + 1, c)).
At the start of the game, the first robot moves from (0, 0) to (1, n-1), collecting all the points from the cells on its path. For all cells (r, c) traversed on the path, grid[r][c] is set to 0. Then, the second robot moves from (0, 0) to (1, n-1), collecting the points on its path. Note that their paths may intersect with one another.
The first robot wants to minimize the number of points collected by the second robot. In contrast, the second robot wants to maximize the number of points it collects. If both robots play optimally, return the number of points collected by the second robot.*/
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
         long long top = 0, bot = 0, min2 = LLONG_MAX;

        // Sum of the first row in matrix[points]
        for (int num : grid[0]) top += num;

        // Loop through each column to simulate both robots
     for (int col = 0; col < grid[0].size(); col++) {
        top -= grid[0][col];  // First robot collects points from the current column
        min2 = min(min2, max(top, bot));  // Minimize the maximum points for the second robot
        bot += grid[1][col];  // Second robot collects points from the current column
    }

    }
};

 
