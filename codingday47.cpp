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
/*Find and Replace Pattern
Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.
A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.
Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.
Example 1:
Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.
Example 2:
Input: words = ["a","b","c"], pattern = "a"
Output: ["a","b","c"]*/
class Solution {
   vector<int> change(string &s, unordered_map<char, vector<int>>& mpp) {
    vector<int> temp;
    for (int i = 0; i < s.size(); i++) {  // Ensuring order
        for (int idx : mpp[s[i]]) {
            temp.push_back(idx);
        }
    }
    return temp;
}

bool check(vector<int>& arr1, vector<int>& arr2) {
    if (arr1.size() != arr2.size()) return false;
    for (int i = 0; i < arr1.size(); i++) {
        if (arr1[i] != arr2[i]) return false;
    }
    return true;
}

public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
          unordered_map<char, vector<int>> mpp;
    vector<string> res;

    for (int i = 0; i < pattern.size(); i++) {
        mpp[pattern[i]].push_back(i);
    }

    vector<int> ans = change(pattern, mpp);
   

    int i = 0;
    while (i < words.size()) {
        if (words[i].size() != pattern.size()) {
            i++;
            continue;
        }

        unordered_map<char, vector<int>> mp;
        string temp = words[i];

        for (int j = 0; j < temp.size(); j++) {
            mp[temp[j]].push_back(j);
        }

        if (mp.size() == mpp.size()) {
            vector<int> tempVec = change(temp, mp);
            bool resCheck = check(ans, tempVec);

            if (resCheck) {
                res.push_back(temp);
            }
        }
        i++;
    }
        return res;
    }
};

