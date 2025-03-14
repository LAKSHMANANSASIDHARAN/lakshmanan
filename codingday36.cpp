/*Generate Binary Strings Without Adjacent Zeros
You are given a positive integer n.
A binary string x is valid if all substrings of x of length 2 contain at least one "1".
Return all valid strings with length n, in any order.
Example 1:
Input: n = 3
Output: ["010","011","101","110","111"]
Explanation:
The valid strings of length 3 are: "010", "011", "101", "110", and "111".
Example 2:
Input: n = 1
Output: ["0","1"]
Explanation:
The valid strings of length 1 are: "0" and "1".*/
class Solution {
public:
    void finding(vector<string>& ans, int n, string s) {
        if (s.size() == n) {
            ans.push_back(s);
            return;
        }
        if (s.size() == 0 || s[s.size() - 1] != '0') {
            finding(ans, n, s + "0");
        }
        finding(ans, n, s + "1");
    }

public:
    vector<string> validStrings(int n) {
        string s = "";
        vector<string> ans;
        finding(ans, n, s);
        return ans;
    }
};
