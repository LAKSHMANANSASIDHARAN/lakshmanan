/*2696. Minimum String Length After Removing Substrings
You are given a string s consisting only of uppercase English letters.
You can apply some operations to this string where, in one operation, you can remove any occurrence of one of the substrings "AB" or "CD" from s.
Return the minimum possible length of the resulting string that you can obtain.
Note that the string concatenates after removing the substring and could produce new "AB" or "CD" substrings.
Example 1:
Input: s = "ABFCACDB"
Output: 2
Explanation: We can do the following operations:
- Remove the substring "ABFCACDB", so s = "FCACDB".
- Remove the substring "FCACDB", so s = "FCAB".
- Remove the substring "FCAB", so s = "FC".
So the resulting length of the string is 2.
It can be shown that it is the minimum length that we can obtain.
Example 2:
Input: s = "ACBBD"
Output: 5
Explanation: We cannot do any operations on the string so the length remains the same.*/
class Solution {
    bool check(stack<char>&st){
        if(st.size()<2) return false;
        stack<char>temp=st;
        string t="";
        t+=st.top();
        temp.pop();
        t+=temp.top();
         if(t=="BA" or t=="DC") return true;
         return false;
    }
public:
    int minLength(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            while(!st.empty() && check(st)){
                st.pop();
                st.pop();
            }
            st.push(s[i]);
        }
        if(check(st)){
              st.pop();
                st.pop();
        }
        return st.size();
    }
};
