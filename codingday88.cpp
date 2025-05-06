/*Check if All A's Appears Before All B's
Given a string s consisting of only the characters 'a' and 'b', return true if every 'a' appears before every 'b' in the string. Otherwise, return false.
Example 1:
Input: s = "aaabbb"
Output: true
Explanation:
The 'a's are at indices 0, 1, and 2, while the 'b's are at indices 3, 4, and 5.
Hence, every 'a' appears before every 'b' and we return true.
Example 2:
Input: s = "abab"
Output: false
Explanation:
There is an 'a' at index 2 and a 'b' at index 1.
Hence, not every 'a' appears before every 'b' and we return false.
Example 3:
Input: s = "bbb"
Output: true
Explanation:
There are no 'a's, hence, every 'a' appears before every 'b' and we return true.*/
class Solution {
public:
    bool checkString(string s) {
        int i=s.size()-1;
       while(i>=0){
        if(s[i]=='a'){
            break;
        }
        else{
        i--;
        }
       }
       int j=0;
       while(j<i){
        if(s[j]=='b'){
            return false;
        }
        j++;
       }
       return true;
    }
};
/*Minimum Moves to Convert String
You are given a string s consisting of n characters which are either 'X' or 'O'.
A move is defined as selecting three consecutive characters of s and converting them to 'O'. Note that if a move is applied to the character 'O', it will stay the same.
Return the minimum number of moves required so that all the characters of s are converted to 'O'.
Example 1:
Input: s = "XXX"
Output: 1
Explanation: XXX -> OOO
We select all the 3 characters and convert them in one move.
Example 2:
Input: s = "XXOX"
Output: 2
Explanation: XXOX -> OOOX -> OOOO
We select the first 3 characters in the first move, and convert them to 'O'.
Then we select the last 3 characters and convert them so that the final string contains all 'O's.
Example 3:
Input: s = "OOOO"
Output: 0
Explanation: There are no 'X's in s to convert.*/
class Solution {
public:
    int minimumMoves(string s) {
      int i=0,count=0;
      while(i<s.size()){
        if(s[i]=='X'){
            count++;
            i=i+3;
        }
        else{
            i++;
        }
      }
       return count;
    }
};
