/*Valid Palindrome II
Given a string s, return true if the s can be palindrome after deleting at most one character from it.
Example 1:
Input: s = "aba"
Output: true
Example 2:
Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:
Input: s = "abc"
Output: false*/
class Solution {
    bool process(string s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int i=0,j=s.size()-1;
        bool check=true;
        while(i<j){
            if(s[i]!=s[j]){
                check=false;
                break;
            }
            i++;
            j--;
        }
        if(check){return true;}
        string temp1="",temp2="";
        int l=0,r=0;
        while(l<s.size()){
            if(l!=i){
            temp1+=s[l];
            }
            l++;
        }
         while(r<s.size()){
            if(r!=j){
            temp2+=s[r];
            }
            r++;
        }
       return (process(temp1) or process(temp2))? true: false;
        
    }
};
