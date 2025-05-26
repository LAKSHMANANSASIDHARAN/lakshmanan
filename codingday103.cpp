/* Longest Palindrome by Concatenating Two Letter Words
You are given an array of strings words. Each element of words consists of two lowercase English letters.
Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.
Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.
A palindrome is a string that reads the same forward and backward.
Example 1:
Input: words = ["lc","cl","gg"]
Output: 6
Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
Note that "clgglc" is another longest palindrome that can be created.
Example 2:
Input: words = ["ab","ty","yt","lc","cl","ab"]
Output: 8
Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
Note that "lcyttycl" is another longest palindrome that can be created.
Example 3:
Input: words = ["cc","ll","xx"]
Output: 2
Explanation: One longest palindrome is "cc", of length 2.
Note that "ll" is another longest palindrome that can be created, and so is "xx".*/
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
      int count=0,maxi=0;
      unordered_map<string,int>mp;
      unordered_set<string>st;
      for(auto i:words){
        mp[i]++;
      }
     bool centerUsed = false;
for(auto &[f,s]:mp){
    string temp = f;
    reverse(temp.begin(), temp.end());
    if(st.find(f) != st.end()) continue;

    if(f == temp){
        if(s % 2 == 0){
            count += s * 2;
        } else {
            count += (s - 1) * 2;
            if(!centerUsed){
                count += 2;
                centerUsed = true;
            }
        }
        st.insert(f);
    } else {
        if(mp.find(temp) != mp.end()){
            count += min(mp[f], mp[temp]) * 4;
        }
        st.insert(f);
        st.insert(temp);
    }
}

     
      return count; 
    }
};
/*Check if Every Row and Column Contains All Numbers
An n x n matrix is valid if every row and every column contains all the integers from 1 to n (inclusive).
Given an n x n integer matrix matrix, return true if the matrix is valid. Otherwise, return false.
Example 1:
Input: matrix = [[1,2,3],[3,1,2],[2,3,1]]
Output: true
Explanation: In this case, n = 3, and every row and column contains the numbers 1, 2, and 3.
Hence, we return true.
Example 2:
Input: matrix = [[1,1,1],[1,2,3],[1,2,3]]
Output: false
Explanation: In this case, n = 3, but the first row and the first column do not contain the numbers 2 or 3.
Hence, we return false.*/
class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        vector<int>temp;
        for(int i=1;i<=matrix.size();i++){
            temp.push_back(i);
        }
        for(int i=0;i<matrix.size();i++){
            vector<int>row,col;
           for(int j=0;j<matrix.size();j++){
                row.push_back(matrix[i][j]);
                col.push_back(matrix[j][i]);
           }
           sort(row.begin(),row.end());
           sort(col.begin(),col.end());
           if(row!=temp or col !=temp){
            return false;
           }
        }
        return true;
    }
};
