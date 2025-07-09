/*Determine if String Halves Are Alike
You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.
Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.
Return true if a and b are alike. Otherwise, return false.
Example 1:
Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
Example 2:
Input: s = "textbook"
Output: false
Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
Notice that the vowel o is counted twice.*/
class Solution {
    bool isvowel(char a){
        if(a=='a' or a=='e' or a=='i' or a=='o' or a=='u' or a=='A' or a=='E' or a=='I' or a=='O' or a=='U'  ){
            return true;
        }
        return false;
    }
public:
    bool halvesAreAlike(string s) {
        //unordered_map<char,int>right,left;
        int right=0,left=0;
        int i=0;
        while(i<s.size()/2){
            if(isvowel(s[i])){
                right++;
            }
            i++;
        }i=s.size()/2;
         while(i<s.size()){
            if(isvowel(s[i])){
                left++;
            }
            i++;
        }
        return right==left;
    }
};
