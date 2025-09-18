/*967. Numbers With Same Consecutive Differences
Given two integers n and k, return an array of all the integers of length n where the difference between every two consecutive digits is k. You may return the answer in any order.
Note that the integers should not have leading zeros. Integers as 02 and 043 are not allowed.
Example 1:
Input: n = 3, k = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
Example 2:
Input: n = 2, k = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]*/
class Solution {
    void res(int n, int k, string& s, vector<int>& ans) {
        if (s.size() == n) {
            ans.push_back(stoi(s));
            return;
        }
        for (int i = 0; i <= 9; i++) {
            if (i == 0 && s.empty()) continue;

            if (s.empty()) {
                s.push_back('0' + i);
                res(n, k, s, ans);
                s.pop_back();
            }
            else if (abs((s.back() - '0') - i) == k) {
                s.push_back('0' + i);
                res(n, k, s, ans);
                s.pop_back();
            }
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        string s = "";
        res(n, k, s, ans);
        return ans;
    }
};
