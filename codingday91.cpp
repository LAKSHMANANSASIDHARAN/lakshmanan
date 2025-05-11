/*Count the Number of Vowel Strings in Range
You are given a 0-indexed array of string words and two integers left and right.
A string is called a vowel string if it starts with a vowel character and ends with a vowel character where vowel characters are 'a', 'e', 'i', 'o', and 'u'.
Return the number of vowel strings words[i] where i belongs to the inclusive range [left, right].
Example 1:
Input: words = ["are","amy","u"], left = 0, right = 2
Output: 2
Explanation: 
- "are" is a vowel string because it starts with 'a' and ends with 'e'.
- "amy" is not a vowel string because it does not end with a vowel.
- "u" is a vowel string because it starts with 'u' and ends with 'u'.
The number of vowel strings in the mentioned range is 2.
Example 2:
Input: words = ["hey","aeo","mu","ooo","artro"], left = 1, right = 4
Output: 3
Explanation: 
- "aeo" is a vowel string because it starts with 'a' and ends with 'o'.
- "mu" is not a vowel string because it does not start with a vowel.
- "ooo" is a vowel string because it starts with 'o' and ends with 'o'.
- "artro" is a vowel string because it starts with 'a' and ends with 'o'.
The number of vowel strings in the mentioned range is 3.*/
class Solution {
    bool iscorrect(string &s){
        int n=s.size()-1;
        if((s[0]=='a' or s[0]=='u' or s[0]=='o' or s[0]=='i' or s[0]=='e') && (s[n]=='a' or s[n]=='u' or s[n]=='o' or s[n]=='i' or s[n]=='e')){
            return true;
        }
        return false;
    }
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int count=0;
        for(int i=left;i<=right;i++){
            if(iscorrect(words[i])){
                count++;
            }
        }
        return count;

    }
};
/*Find Valid Pair of Adjacent Digits in String
You are given a string s consisting only of digits. A valid pair is defined as two adjacent digits in s such that:
The first digit is not equal to the second.
Each digit in the pair appears in s exactly as many times as its numeric value.
Return the first valid pair found in the string s when traversing from left to right. If no valid pair exists, return an empty string.
Example 1:
Input: s = "2523533"
Output: "23"
Explanation:
Digit '2' appears 2 times and digit '3' appears 3 times. Each digit in the pair "23" appears in s exactly as many times as its numeric value. Hence, the output is "23".
Example 2:
Input: s = "221"
Output: "21"
Explanation:
Digit '2' appears 2 times and digit '1' appears 1 time. Hence, the output is "21".
Example 3:
Input: s = "22"
Output: ""
Explanation:
There are no valid adjacent pairs.*/
class Solution {
    bool is(char f,char t, vector<int>&hash){
        int num1=f-'0',num2=t-'0';
        if(num1==hash[f-'0']&&num2==hash[t-'0']){
            return true;
        }
        return false;
    }
public:
    string findValidPair(string s) {
        vector<int>hash(10,0);
        for(auto it:s){
            hash[it-'0']++;
        }
        string ans="";
        int f=0,t=1;
        while(t<s.size()){
            if(s[f]!=s[t]&&is(s[f],s[t],hash)){
               ans+=s[f];
               ans+=s[t];
               break; 
            }
            f++;
            t++;
        }
        return ans;
        
    }
};
