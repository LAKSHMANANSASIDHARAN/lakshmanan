/*Backspace String Compare
Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
Note that after backspacing an empty text, the text will continue empty.
Example 1:
Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
Example 2:
Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
Example 3:
Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".*/
class Solution {
    string check(string s,string temp){
        int l=s.size()-1,count =0 ;
        while(l>=0){
             if (s[l] == '#') {
                count++;
                l--;
            } else if (count > 0) {
                count--;
                l--;
            } else {
                temp += s[l];
                l--;
            }
        }
        return temp;
    }
public:
    bool backspaceCompare(string s, string t) {
        string temp1="",temp2="";
        return check(s,temp1)==check(t,temp2);
    }
};
