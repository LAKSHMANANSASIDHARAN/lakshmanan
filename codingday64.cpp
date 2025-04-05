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
