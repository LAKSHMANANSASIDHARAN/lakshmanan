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
/*Shortest Distance to a Character
Given a string s and a character c that occurs in s, return an array of integers answer where answer.length == s.length and answer[i] is the distance from index i to the closest occurrence of character c in s.
The distance between two indices i and j is abs(i - j), where abs is the absolute value function.
Example 1:
Input: s = "loveleetcode", c = "e"
Output: [3,2,1,0,1,0,0,1,2,2,1,0]
Explanation: The character 'e' appears at indices 3, 5, 6, and 11 (0-indexed).
The closest occurrence of 'e' for index 0 is at index 3, so the distance is abs(0 - 3) = 3.
The closest occurrence of 'e' for index 1 is at index 3, so the distance is abs(1 - 3) = 2.
For index 4, there is a tie between the 'e' at index 3 and the 'e' at index 5, but the distance is still the same: abs(4 - 3) == abs(4 - 5) = 1.
The closest occurrence of 'e' for index 8 is at index 6, so the distance is abs(8 - 6) = 2.
Example 2:
Input: s = "aaab", c = "b"
Output: [3,2,1,0]*/
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
       vector<int>temp,ans;
     for(int i=0;i<s.size();i++){
        if(s[i]==c){
            temp.push_back(i);
        }
     }
     int i=0,j=0;
     while(i<s.size()){
        if(s[i]==c and j<temp.size()-1){
            ans.push_back(0);
            j++;
        }
      else  if(j==0  ){
            ans.push_back(abs(i-temp[j]));
        }
        else if(j==temp.size()){
           ans.push_back(abs(i-temp[j-1]));
        }
        else{
            ans.push_back(min(abs(i-temp[j]),abs(i-temp[j-1])));
        if(i>=temp[j])    j++;
        }
        i++;
     }
         return ans;
    }
};
