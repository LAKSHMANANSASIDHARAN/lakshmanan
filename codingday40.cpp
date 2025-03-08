/* Decode String
Given an encoded string, return its decoded string.
The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].
The test cases are generated so that the length of the output will never exceed 105.
Example 1:
Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:
Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:
Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"*/
class Solution {
public:
    string gen(stack<char>& st1) {
        string temp1 = "", temp2 = "";

        while (!st1.empty() && st1.top() != '[') {
            temp1 = st1.top() + temp1;
            st1.pop();
        }

        st1.pop(); 

        string numStr = "";
        while (!st1.empty() && isdigit(st1.top())) {
            numStr = st1.top() + numStr;
            st1.pop();
        }

        int num = stoi(numStr);
        while (num--) {
            temp2 += temp1;
        }

        return temp2;
    }

public:
    string decodeString(string s) {
        stack<char> st1;
        stack<char> st2;
        int i = 0;
        string ans = "";

        while (i < s.size()) {
            if (s[i] == '[') {
                st2.push('[');
                st1.push(s[i]);
            } else if (s[i] == ']') {
                st2.pop();
                string decoded = gen(st1);
                for (char c : decoded) {
                    st1.push(c);
                }
            } else {
                st1.push(s[i]);
            }
            i++;
        }

        while (!st1.empty()) {
            ans = st1.top() + ans;
            st1.pop();
        }

        return ans;
    }
};
