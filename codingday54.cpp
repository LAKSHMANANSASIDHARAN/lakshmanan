/*Find All Anagrams in a String
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
Example 1:
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:
Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) return {}; 
        
        vector<int> phash(26, 0), shash(26, 0), ans;
        
        for (int i = 0; i < p.size(); i++) {
            phash[p[i] - 'a']++;
            shash[s[i] - 'a']++;
        }
        
        int i = 0, j = p.size();
        if (phash == shash) ans.push_back(i);
        
        while (j < s.size()) {
            shash[s[i] - 'a']--;
            shash[s[j] - 'a']++;
            i++; j++;
            if (phash == shash) ans.push_back(i);
        }
        
        return ans;
    }
};
