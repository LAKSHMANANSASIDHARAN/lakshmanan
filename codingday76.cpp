/*Minimum Deletions to Make String Balanced
You are given a string s consisting only of characters 'a' and 'b'​​​​.
You can delete any number of characters in s to make s balanced. s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.
Return the minimum number of deletions needed to make s balanced.
Example 1:
Input: s = "aababbab"
Output: 2
Explanation: You can either:
Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").
Example 2:
Input: s = "bbaaaaabb"
Output: 2
Explanation: The only solution is to delete the first two characters.*/
class Solution {
public:
    int minimumDeletions(string s) {
        int count = 0;
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (!st.empty() && s[i] == 'a' && st.top() == 'b') {
                st.pop();
                count++;
            }
            else{
            st.push(s[i]);
            }
        }
        return count;
    }
};
/* Minimum Add to Make Parentheses Valid
A parentheses string is valid if and only if:
It is the empty string,
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.
For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
Return the minimum number of moves required to make s valid.
Example 1:
Input: s = "())"
Output: 1
Example 2:
Input: s = "((("
Output: 3
 */
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(!st.empty()&&st.top()=='('&&s[i]==')'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
           
        }
         return st.size();
    }
};
