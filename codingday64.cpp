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
