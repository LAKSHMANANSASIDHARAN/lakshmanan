/*Remove Outermost Parentheses !!
they have given the string that has paraentheses , we should remove only outermost parentheses and return balance string as it is
basically we can solve this by using many way. But using stack is good practice for learing stack
lets see the exmaple:
Example 1:
Input: s = "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".
Example 2:
Input: s = "(()())(())(()(()))"
Output: "()()()()(())"
Explanation: 
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".
Example 3:
Input: s = "()()"
Output: ""
Explanation: 
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".*/
string removeOuterParentheses(string org) {
        string para="";
         int i=0;
         stack<string>st;
         int n=org.size();
         char ch='(';
         while(i<n){
          if(org[i]==ch){
            if(st.empty()){
              st.push("(");
            
            }
            else{
              para=para+"(";
              st.push("(");
            }
          }
          else {
            if(st.size()>1){
              para=para+")";
              st.pop();
              }
              else{
                st.pop();
              }
                
          }
          i++;
         }
     return  para; 
    }
/*Find the Index of the First Occurrence in a String 
they have given the two string we need to find the starting index of second string in the first string if the total second string was occured in first string 
otherwise return -1
Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.*/
int strStr(string haystack, string needle) {
        int i=0,j=0;
        while(i<haystack.size()){
            if(haystack[i]!=needle[j]){
                 i=i-j+1;
                j=0;
            }
            else{
                j++;i++ ;
            }
            if(j==needle.size()) {
            return i-j;
         }
        }
        return -1;
    }
