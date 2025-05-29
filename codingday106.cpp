/*Longest Substring with At Least K Repeating Characters
Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.
if no such substring exists, return 0.
Example 1:
Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:
Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
 */
class Solution {
public:
    int longestSubstring(string& s, int k, int start, int end) {
        vector<int> hash(26, 0);
        for (int i = start; i < end; i++) {
            hash[s[i] - 'a']++;
        }

        for (int i = start; i < end; i++) {
            if (hash[s[i] - 'a'] < k) {
                int j = i + 1;
                while (j < end && hash[s[j] - 'a'] < k) j++;
                return max(longestSubstring(s, k, start, i), longestSubstring(s, k, j, end));
            }
        }

        return end - start;
    }

    int longestSubstring(string s, int k) {
        return longestSubstring(s, k, 0, s.size());
    }
};
