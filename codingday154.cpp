/*79. Word Search
Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false*/
class Solution {
    bool dfs(int i,int j,int ind,
             vector<vector<char>>& board, 
             string &word, 
             vector<vector<bool>>& visited) {

        if(ind == word.size()) return true; 
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size()) return false;
        if(visited[i][j]) return false;
        if(board[i][j] != word[ind]) return false;

        
        visited[i][j] = true;

        bool found = dfs(i+1,j,ind+1,board,word,visited) ||
                     dfs(i-1,j,ind+1,board,word,visited) ||
                     dfs(i,j+1,ind+1,board,word,visited) ||
                     dfs(i,j-1,ind+1,board,word,visited);

        
        visited[i][j] = false;
        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0]) {
                    if(dfs(i,j,0,board,word,visited)) return true;
                }
            }
        }
        return false;
    }
};
