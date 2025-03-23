/*Maximum Number of Vowels in a Substring of Given Length
Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.
Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.
Example 1:
Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:
Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:
Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.*/
class Solution {
public:
    int maxVowels(string s, int k) {
        int l = 0, r = 0, count = 0, maxi = 0;
        unordered_map<char, int> mpp;
        int n = s.size();
        
        while (r < n) {
            if (s[r] == 'a' || s[r] == 'e' || s[r] == 'i' || s[r] == 'o' || s[r] == 'u') {
                count++;
                mpp[s[r]]++;
            }

            if (r - l + 1 == k) {
                maxi = max(maxi, count);
                if (s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u') {
                    mpp[s[l]]--;
                    count--;
                }
                l++;
            }
            
            r++;
        }
        
        return maxi;
    }
};
