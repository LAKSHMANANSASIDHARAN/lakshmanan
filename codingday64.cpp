/*Check if All Characters Have Equal Number of Occurrences
Given a string s, return true if s is a good string, or false otherwise.
A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).
Example 1:
Input: s = "abacbc"
Output: true
Explanation: The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.
Example 2:
Input: s = "aaabb"
Output: false
Explanation: The characters that appear in s are 'a' and 'b'.
'a' occurs 3 times while 'b' occurs 2 times, which is not the same number of times.*/
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int>freq(26,0);
        for(auto it:s){
          freq[it-'a']++;
        }
        int check=freq[s[0]-'a'];
        int i=1;
        while(i<s.size()){
            if(freq[s[i]-'a']!=check){
                return false;
            }
            i++;
        }
        return true;
    }
};
/* Sum of Unique Elements
You are given an integer array nums. The unique elements of an array are the elements that appear exactly once in the array.
Return the sum of all the unique elements of nums.
Example 1:
Input: nums = [1,2,3,2]
Output: 4
Explanation: The unique elements are [1,3], and the sum is 4.
Example 2:
Input: nums = [1,1,1,1,1]
Output: 0
Explanation: There are no unique elements, and the sum is 0.
Example 3:
Input: nums = [1,2,3,4,5]
Output: 15
Explanation: The unique elements are [1,2,3,4,5], and the sum is 15.*/
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
     vector<int>freq(100+1,0);
        for(auto it:nums){
            freq[it]++;
        }
        int i=0;
        int sum=0;
        while(i<nums.size()){
            if(freq[nums[i]]==1){
                sum+=nums[i];
            }
            i++;
        }
        return sum;
     }   
    
};
/*Unique Number of Occurrences
Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.
Example 1:
Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:
Input: arr = [1,2]
Output: false
Example 3:
Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true*/
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       unordered_map<int,int>mp;
       for(auto it:arr){
        mp[it]++;
       }
       vector<int>temp;
       for(auto it:mp){
        temp.push_back(it.second);
       }
       sort(temp.begin(),temp.end());
       for(int i=0;i<temp.size()-1;i++){
        if(temp[i]==temp[i+1]){
            return false;
        }
       }
       return true;
    }
};
/* Count Pairs That Form a Complete Day I
Given an integer array hours representing times in hours, return an integer denoting the number of pairs i, j where i < j and hours[i] + hours[j] forms a complete day.
A complete day is defined as a time duration that is an exact multiple of 24 hours.
For example, 1 day is 24 hours, 2 days is 48 hours, 3 days is 72 hours, and so on.
Example 1:
Input: hours = [12,12,30,24,24]
Output: 2
Explanation:
The pairs of indices that form a complete day are (0, 1) and (3, 4).
Example 2:
Input: hours = [72,48,24,3]
Output: 3
Explanation:
The pairs of indices that form a complete day are (0, 1), (0, 2), and (1, 2).*/
class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int count=0;
        for(int i=0;i<hours.size()-1;i++){
            for(int j=i+1;j<hours.size();j++){
                int sum=hours[i]+hours[j];
                if(sum%24==0){
                    count++;
                }
            }
        }
        return count;
    }
};
/*Minimize String Length
Given a string s, you have two types of operation:
Choose an index i in the string, and let c be the character in position i. Delete the closest occurrence of c to the left of i (if exists).
Choose an index i in the string, and let c be the character in position i. Delete the closest occurrence of c to the right of i (if exists).
Your task is to minimize the length of s by performing the above operations zero or more times.
Return an integer denoting the length of the minimized string.
Example 1:
Input: s = "aaabc"
Output: 3
Explanation:
Operation 2: we choose i = 1 so c is 'a', then we remove s[2] as it is closest 'a' character to the right of s[1].
s becomes "aabc" after this.
Operation 1: we choose i = 1 so c is 'a', then we remove s[0] as it is closest 'a' character to the left of s[1].
s becomes "abc" after this.
Example 2:
Input: s = "cbbd"
Output: 3
Explanation:
Operation 1: we choose i = 2 so c is 'b', then we remove s[1] as it is closest 'b' character to the left of s[1].
s becomes "cbd" after this.
Example 3:
Input: s = "baadccab"
Output: 4
Explanation:
Operation 1: we choose i = 6 so c is 'a', then we remove s[2] as it is closest 'a' character to the left of s[6].
s becomes "badccab" after this.
Operation 2: we choose i = 0 so c is 'b', then we remove s[6] as it is closest 'b' character to the right of s[0].
s becomes "badcca" fter this.
Operation 2: we choose i = 3 so c is 'c', then we remove s[4] as it is closest 'c' character to the right of s[3].
s becomes "badca" after this.
Operation 1: we choose i = 4 so c is 'a', then we remove s[1] as it is closest 'a' character to the left of s[4].
s becomes "bdca" after this.*/
class Solution {
public:
    int minimizedStringLength(string s) {
      vector<int>freq(26,0);
      int count=0;
      for(auto it:s){
          if(freq[it-'a']==1){
            continue;
          }
          else if(freq[it-'a']==0){
            freq[it-'a']++;
            count++;
          }
      }  
      return count;
    }
};
