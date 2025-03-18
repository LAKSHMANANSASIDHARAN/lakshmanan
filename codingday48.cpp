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
/*Strictly Palindromic Number
An integer n is strictly palindromic if, for every base b between 2 and n - 2 (inclusive), the string representation of the integer n in base b is palindromic.
Given an integer n, return true if n is strictly palindromic and false otherwise.
A string is palindromic if it reads the same forward and backward.
Example 1:
Input: n = 9
Output: false
Explanation: In base 2: 9 = 1001 (base 2), which is palindromic.
In base 3: 9 = 100 (base 3), which is not palindromic.
Therefore, 9 is not strictly palindromic so we return false.
Note that in bases 4, 5, 6, and 7, n = 9 is also not palindromic.
Example 2:
Input: n = 4
Output: false
Explanation: We only consider base 2: 4 = 100 (base 2), which is not palindromic.
Therefore, we return false.*/
class Solution {
    string convert(int n,int i){
        string temp; 
        while(n){
          temp+=to_string(n%i);
          n=n/2;
        }
        return temp;
    }
    bool pal(string binary){
        string temp=binary;
        reverse(binary.begin(),binary.end());
        return temp==binary;
    }
public:
    bool isStrictlyPalindromic(int n) {
        for(int i=2;i<=n-2;i++){
            string binary=convert(n,i);
            bool check=pal(binary);
            if(!check){return false;}
        }
        return true;
    }
};
