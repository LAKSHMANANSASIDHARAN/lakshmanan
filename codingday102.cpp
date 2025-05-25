/* Reverse Only Letters
Given a string s, reverse the string according to the following rules:
All the characters that are not English letters remain in the same position.
All the English letters (lowercase or uppercase) should be reversed.
Return s after reversing it.
Example 1:
Input: s = "ab-cd"
Output: "dc-ba"
Example 2:
Input: s = "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
Example 3:
Input: s = "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"*/
class Solution {
    bool check(char c){
         if(c>='A' and c<='Z'){
            return true;
         }
         else if(c>='a' and c<='z'){
            return true;
         }
         else{
            return false;
         }
    }
public:
    string reverseOnlyLetters(string s) {
        int l=0,r=s.size()-1;
        while(l<r){
            if(!check(s[l])){
                l++;
            }
            if(!check(s[r])){
                r--;
            }
            else if(check(s[l])&& check(s[r])){
                swap(s[l],s[r]);
                l++;
                r--;
            }

        }
        return s;
    }
};
