/*Minimum Remove to Make Valid Parentheses
Given a string s of '(' , ')' and lowercase English characters.
Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.
Formally, a parentheses string is valid if and only if:
It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
Example 1:
Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
Example 2:
Input: s = "a)b(c)d"
Output: "ab(c)d"
Example 3:
Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.*/
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> open, close;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open.push(i);
            } else if (s[i] == ')') {
                if (!open.empty()) {
                    open.pop();
                } else {
                    close.push(i);
                }
            }
        }

        unordered_set<int> st;
        while (!open.empty()) {
            st.insert(open.top());
            open.pop();
        }
        while (!close.empty()) {
            st.insert(close.top());
            close.pop();
        }

        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (st.find(i) == st.end()) {
                ans += s[i];
            }
        }
        return ans;
    }
};
/*Make The String Great
Given a string s of lower and upper case English letters.
A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:
0 <= i <= s.length - 2
s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.
To make the string good, you can choose two adjacent characters that make the string bad and remove them. You can keep doing this until the string becomes good.
Return the string after making it good. The answer is guaranteed to be unique under the given constraints.
Notice that an empty string is also good.
Example 1:
Input: s = "leEeetcode"
Output: "leetcode"
Explanation: In the first step, either you choose i = 1 or i = 2, both will result "leEeetcode" to be reduced to "leetcode".
Example 2:
Input: s = "abBAcC"
Output: ""
Explanation: We have many possible scenarios, and all lead to the same answer. For example:
"abBAcC" --> "aAcC" --> "cC" --> ""
"abBAcC" --> "abBA" --> "aA" --> ""
Example 3:
Input: s = "s"
Output: "s"
 */
class Solution {
    public:
    string makeGood(string s) {
       string ans="";
       stack<char>st;
       for(int i=0;i<s.size();i++){
        
         if(!st.empty()&&abs(st.top()-s[i])==32){
            st.pop();
            continue;
         }
         st.push(s[i]);
       }
       while(!st.empty()){
        ans=st.top()+ans;
        st.pop();
       }
       return ans;

    }
};
