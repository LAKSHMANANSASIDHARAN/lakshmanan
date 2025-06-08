/*Counting Words With a Given Prefix
You are given an array of strings words and a string pref.
Return the number of strings in words that contain pref as a prefix.
A prefix of a string s is any leading contiguous substring of s.
Example 1:
Input: words = ["pay","attention","practice","attend"], pref = "at"
Output: 2
Explanation: The 2 strings that contain "at" as a prefix are: "attention" and "attend".
Example 2:
Input: words = ["leetcode","win","loops","success"], pref = "code"
Output: 0
Explanation: There are no strings that contain "code" as a prefix.*/
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
       
        for(int i=0;i<words.size();i++){
           int j=0;
           string temp;
           string temp_2=words[i];
           if(words[i].size()<pref.size()) continue;
           while(j<pref.size()){
            temp+=temp_2[j];
            j++;
           }
            if(temp==pref) count++;
        }
        
        return count;
    }
};
/* To Lower Case
Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.
Example 1:
Input: s = "Hello"
Output: "hello"
Example 2:
Input: s = "here"
Output: "here"
Example 3:
Input: s = "LOVELY"
Output: "lovely*/
class Solution {
public:
    string toLowerCase(string s) {
        for(auto &c:s){
            if(isupper(c)){
                c=tolower(c);
            }
        }
        return s;
    }
/*Check if a String Is an Acronym of Words
Given an array of strings words and a string s, determine if s is an acronym of words.
The string s is considered an acronym of words if it can be formed by concatenating the first character of each string in words in order. For example, "ab" can be formed from ["apple", "banana"], but it can't be formed from ["bear", "aardvark"].
Return true if s is an acronym of words, and false otherwise.
Example 1:
Input: words = ["alice","bob","charlie"], s = "abc"
Output: true
Explanation: The first character in the words "alice", "bob", and "charlie" are 'a', 'b', and 'c', respectively. Hence, s = "abc" is the acronym. 
Example 2:
Input: words = ["an","apple"], s = "a"
Output: false
Explanation: The first character in the words "an" and "apple" are 'a' and 'a', respectively. 
The acronym formed by concatenating these characters is "aa". 
Hence, s = "a" is not the acronym.
Example 3:
Input: words = ["never","gonna","give","up","on","you"], s = "ngguoy"
Output: true
Explanation: By concatenating the first character of the words in the array, we get the string "ngguoy". 
Hence, s = "ngguoy" is the acronym.
 */
};
class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
       int j=0;
       if(words.size()!=s.size() ) return false;
     for(int i=0;i<words.size();i++){
        string temp=words[i];
        if(temp[0]!=s[j]){
            return false;
        }
        j++;
     }
     return true;
    }
};
/*Maximum Nesting Depth of the Parentheses
Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.
Example 1:
Input: s = "(1+(2*3)+((8)/4))+1"
Output: 3
Explanation:
Digit 8 is inside of 3 nested parentheses in the string.
Example 2:
Input: s = "(1)+((2))+(((3)))"
Output: 3
Explanation:
Digit 3 is inside of 3 nested parentheses in the string.
Example 3:
Input: s = "()(())((()()))"
Output: 3*/
class Solution {
public:
    int maxDepth(string s) {
        int open=0,maxi=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                open++;
            }
            else if(s[i]==')'){
                open--;
            }
            maxi=max(open,maxi);
        }
        return maxi;
    }
};
