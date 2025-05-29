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
/*Longest Repeating Character Replacement
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.
Example 1:
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>mp(26,0);
        int l=0,r=0,maxlen=0,maxi=0;
        while(r<s.size()){
            mp[s[r]-'A']++;
            maxi=max(maxi,mp[s[r]-'A']);
            int len=r-l+1;
            if(len-maxi<=k){
                maxlen=max(maxlen,len);
              
            }
            else{
                mp[s[l]-'A']--;
                l++;

            }
            r++;
        }
        return maxlen;
    }
};
