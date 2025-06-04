/*Convert Date to Binary
You are given a string date representing a Gregorian calendar date in the yyyy-mm-dd format.
date can be written in its binary representation obtained by converting year, month, and day to their binary representations without any leading zeroes and writing them down in year-month-day format.
Return the binary representation of date.
Example 1:
Input: date = "2080-02-29"
Output: "100000100000-10-11101"
Explanation:
100000100000, 10, and 11101 are the binary representations of 2080, 02, and 29 respectively.
Example 2:
Input: date = "1900-01-01"
Output: "11101101100-1-1"
Explanation:
11101101100, 1, and 1 are the binary representations of 1900, 1, and 1 respectively.*/
class Solution {
    int process(string s) {
        int num = 0;
        int i = 0;
        while (i < s.size()) {
            num = num * 10 + (s[i] - '0');
            i++;
        }
        return num;
    }

    string process_two(int num) {
        if (num == 0) return "0";
        string temp = "";
        while (num) {
            temp += to_string(num % 2);
            num /= 2;
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }

public:
    string convertDateToBinary(string date) {
        vector<int> temp;
        vector<string> con;
        string s = "";
        for (int i = 0; i < date.size(); i++) {
            if (date[i] == '-') {
                temp.push_back(process(s));
                s = "";
            } else {
                s += date[i];
            }
        }
        temp.push_back(process(s));
        for (auto i : temp) {
            con.push_back(process_two(i));
        }
        string res = "";
        res += con[0];
        res += '-';
        res += con[1];
        res += '-';
        res += con[2];
        return res;
    }
};
/*Check If Two String Arrays are Equivalent
Solved
Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.
A string is represented by an array if the array elements concatenated in order forms the string.
Example 1:
Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
Output: true
Explanation:
word1 represents string "ab" + "c" -> "abc"
word2 represents string "a" + "bc" -> "abc"
The strings are the same, so return true.
Example 2:
Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
Output: false
Example 3:
Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
Output: true*/
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string temp1="",temp2="";
        int i=0,j=0;
        while(i<word1.size() || j<word2.size()){
            if(i<word1.size()){
                temp1+=word1[i];
                i++;
            }
            if(j<word2.size()){
                temp2+=word2[j];
                j++;
            }
        }
        return temp1==temp2;
    }
};
/* Hash Divided String
You are given a string s of length n and an integer k, where n is a multiple of k. Your task is to hash the string s into a new string called result, which has a length of n / k.
First, divide s into n / k substrings, each with a length of k. Then, initialize result as an empty string.
For each substring in order from the beginning:
The hash value of a character is the index of that character in the English alphabet (e.g., 'a' → 0, 'b' → 1, ..., 'z' → 25).
Calculate the sum of all the hash values of the characters in the substring.
Find the remainder of this sum when divided by 26, which is called hashedChar.
Identify the character in the English lowercase alphabet that corresponds to hashedChar.
Append that character to the end of result.
Return result.
Example 1:
Input: s = "abcd", k = 2
Output: "bf"
Explanation:
First substring: "ab", 0 + 1 = 1, 1 % 26 = 1, result[0] = 'b'.
Second substring: "cd", 2 + 3 = 5, 5 % 26 = 5, result[1] = 'f'.
Example 2:
Input: s = "mxz", k = 3
Output: "i"
Explanation:
The only substring: "mxz", 12 + 23 + 25 = 60, 60 % 26 = 8, result[0] = 'i'.*/
class Solution {
public:
    string stringHash(string s, int k) {
        vector<char>ch;
            char c='a';
        for(int i=0;i<26;i++){
            ch.push_back(c+i);
        }
        vector<int>hash;
        int sum=0;
        for(auto i:s){
            sum+=i-'a';
            hash.push_back(sum);
        }
        int prev=0;
        int i=k-1;
        string res="";
        int temp;
        while(i<hash.size()){
           temp=hash[i]-prev;
           int temp2=temp%26;
           res+=ch[temp2];
           prev=hash[i];
           i+=k;

        }
        return res;
    }
};
/*Find Most Frequent Vowel and Consonant
You are given a string s consisting of lowercase English letters ('a' to 'z').
Your task is to:
Find the vowel (one of 'a', 'e', 'i', 'o', or 'u') with the maximum frequency.
Find the consonant (all other letters excluding vowels) with the maximum frequency.
Return the sum of the two frequencies.
Note: If multiple vowels or consonants have the same maximum frequency, you may choose any one of them. If there are no vowels or no consonants in the string, consider their frequency as 0.
The frequency of a letter x is the number of times it occurs in the string.
Example 1:
Input: s = "successes"
Output: 6
Explanation:
The vowels are: 'u' (frequency 1), 'e' (frequency 2). The maximum frequency is 2.
The consonants are: 's' (frequency 4), 'c' (frequency 2). The maximum frequency is 4.
The output is 2 + 4 = 6.
Example 2:
Input: s = "aeiaeia"
Output: 3
Explanation:
The vowels are: 'a' (frequency 3), 'e' ( frequency 2), 'i' (frequency 2). The maximum frequency is 3.
There are no consonants in s. Hence, maximum consonant frequency = 0.
The output is 3 + 0 = 3.*/
class Solution {
    int find(unordered_map<char,int>&mp){
        if(mp.empty()) return 0;
        int maxi=INT_MIN;
        for(auto i:mp){
              maxi=max(maxi,i.second);
        }
        return maxi;
    }
public:
    int maxFreqSum(string s) {
        unordered_map<char,int>vol,cons;
        for(auto i:s){
            if(i=='a' or i=='e' or i=='o' or i=='u' or i=='i'){
                vol[i]++;
            }
            else{
                cons[i]++;
            }
        }
        int maxivol=find(vol);
        int maxicons=find(cons);
        return maxivol+maxicons;
    }
};
/*Number of Laser Beams in a Bank
Anti-theft security devices are activated inside a bank. You are given a 0-indexed binary string array bank representing the floor plan of the bank, which is an m x n 2D matrix. bank[i] represents the ith row, consisting of '0's and '1's. '0' means the cell is empty, while'1' means the cell has a security device.
There is one laser beam between any two security devices if both conditions are met:
The two devices are located on two different rows: r1 and r2, where r1 < r2.
For each row i where r1 < i < r2, there are no security devices in the ith row.
Laser beams are independent, i.e., one beam does not interfere nor join with another.
Return the total number of laser beams in the bank.
Example 1:
Input: bank = ["011001","000000","010100","001000"]
Output: 8
Explanation: Between each of the following device pairs, there is one beam. In total, there are 8 beams:
 * bank[0][1] -- bank[2][1]
 * bank[0][1] -- bank[2][3]
 * bank[0][2] -- bank[2][1]
 * bank[0][2] -- bank[2][3]
 * bank[0][5] -- bank[2][1]
 * bank[0][5] -- bank[2][3]
 * bank[2][1] -- bank[3][2]
 * bank[2][3] -- bank[3][2]
Note that there is no beam between any device on the 0th row with any on the 3rd row.
This is because the 2nd row contains security devices, which breaks the second condition.
Example 2:
Input: bank = ["000","111","000"]
Output: 0
Explanation: There does not exist two devices located on two different rows.
 */
class Solution {
    int process(string s){
        int count=0;
        for(auto i:s){
            if(i=='1'){
                count++;
            }
        }
        return count;
    }
public:
    int numberOfBeams(vector<string>& bank) {
       vector<int>temp;
      for(int i=0;i<bank.size();i++){
        int temp2=process(bank[i]);
        if(temp2!=0){
        temp.push_back(temp2);
        }
      }
      int i=0,j=1,res=0;
      while(j<temp.size()){
          res+=temp[i]*temp[j];
            i++;j++;
        }
      return res;

    }
};
