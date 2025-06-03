/*Take K of Each Character From Left and Right
You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k. Each minute, you may take either the leftmost character of s, or the rightmost character of s.
Return the minimum number of minutes needed for you to take at least k of each character, or return -1 if it is not possible to take k of each character.
Example 1:
Input: s = "aabaaaacaabc", k = 2
Output: 8
Explanation: 
Take three characters from the left of s. You now have two 'a' characters, and one 'b' character.
Take five characters from the right of s. You now have four 'a' characters, two 'b' characters, and two 'c' characters.
A total of 3 + 5 = 8 minutes is needed.
It can be proven that 8 is the minimum number of minutes needed.
Example 2:
Input: s = "a", k = 1
Output: -1
Explanation: It is not possible to take one 'b' or 'c' so return -1.*/
class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        int freq[3] = {0};

        int left = 0;
        while (left < n && (freq[0] < k || freq[1] < k || freq[2] < k)) {
            freq[s[left] - 'a']++;
            left++;
        }

        if (freq[0] < k || freq[1] < k || freq[2] < k)
            return -1;

        int shortest = left;
        left--;
        int right = n - 1;

        while (left >= 0) {
            freq[s[left] - 'a']--;
            left--;

            while (left < right && (freq[0] < k || freq[1] < k || freq[2] < k)) {
                freq[s[right] - 'a']++;
                right--;
            }

            shortest = min(shortest, n - (right - left));
        }

        return shortest;
    }
};
/*Partitioning Into Minimum Number Of Deci-Binary Numbers
A decimal number is called deci-binary if each of its digits is either 0 or 1 without any leading zeros. For example, 101 and 1100 are deci-binary, while 112 and 3001 are not.
Given a string n that represents a positive decimal integer, return the minimum number of positive deci-binary numbers needed so that they sum up to n.
Example 1:
Input: n = "32"
Output: 3
Explanation: 10 + 11 + 11 = 32
Example 2:
Input: n = "82734"
Output: 8
Example 3:
Input: n = "27346209830709182346"
Output: 9*/
class Solution {
public:
    int minPartitions(string n) {
       int mini=INT_MIN;
        for(auto i:n){
            if((i-'0')>mini){
                mini=i-'0';
            }
        }
        return mini;
    }
};
