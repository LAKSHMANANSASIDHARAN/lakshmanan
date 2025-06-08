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
};
