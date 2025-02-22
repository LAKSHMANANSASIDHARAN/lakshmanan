/*Count the Number of Consistent Strings
You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.
Return the number of consistent strings in the array words.
Example 1:
Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
Example 2:
Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
Output: 7
Explanation: All strings are consistent.
Example 3:
Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
Output: 4
Explanation: Strings "cc", "acd", "ac", and "d" are consistent.*/
class Solution {
public:
    bool check(string str, vector<int> arr) {
        int i;
        for (i = 0; i < str.size(); i++) {
            if (arr[str[i] - 'a'] == 0) {
                return false;
                break;
            }
        }
        return true;
    }

public:
    int countConsistentStrings(string s, vector<string>& str) {
        int result = 0;
        vector<int> arr(26, 0);
        for (auto it : s) {
            arr[it - 'a']++;
        }

        for (auto it : str) {
            bool temp = check(it, arr);
            if (temp) {
                result++;
            }
        }
        return result;
    }
};
/*Permutation Difference between Two Strings
You are given two strings s and t such that every character occurs at most once in s and t is a permutation of s.
The permutation difference between s and t is defined as the sum of the absolute difference between the index of the occurrence of each character in s and the index of the occurrence of the same character in t.
Return the permutation difference between s and t.
Example 1:
Input: s = "abc", t = "bac"
Output: 2
Explanation:
For s = "abc" and t = "bac", the permutation difference of s and t is equal to the sum of:
The absolute difference between the index of the occurrence of "a" in s and the index of the occurrence of "a" in t.
The absolute difference between the index of the occurrence of "b" in s and the index of the occurrence of "b" in t.
The absolute difference between the index of the occurrence of "c" in s and the index of the occurrence of "c" in t.
That is, the permutation difference between s and t is equal to |0 - 1| + |1 - 0| + |2 - 2| = 2.
Example 2:
Input: s = "abcde", t = "edbac"
Output: 12
Explanation: The permutation difference between s and t is equal to |0 - 3| + |1 - 2| + |2 - 4| + |3 - 1| + |4 - 0| = 12.*/
class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<int, pair<int, int>> mpp;
        for (int i = 0; i < s.size(); i++) {
            mpp[s[i]].first = i;
        }
        for (int i = 0; i < t.size(); i++) {
            mpp[t[i]].second = i;
        }
        int result = 0;
        int i;
        for (i = 0; i < s.size(); i++) {
            result += abs(mpp[s[i]].first - mpp[s[i]].second);
        }
        return result;
    }
};
