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
/*Reverse String II
Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.
If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.
Example 1:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Example 2:
Input: s = "abcd", k = 2
Output: "bacd"
 */
class Solution {
    void reversestring(string &s,int i,int j){
         
         while(i<j){
            swap(s[i],s[j]);
            i++;j--;
         }
    }
public:
    string reverseStr(string &s, int k) {
        int i=0,j=2*k-1;
        while(j<s.size()){
           reversestring(s,i,i+k-1);
           i=j+1;
           j+=2*k;
        }
        int n=s.size();
        if(i<n && n-i<k){
           reversestring(s,i,n-1);
        }
        else if(i<n && n-i<2*k && n-i>=k){
            reversestring(s,i,i+k-1);
        }
        return s;
    }
};
