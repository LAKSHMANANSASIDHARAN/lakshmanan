/*Optimal Partition of String
Given a string s, partition the string into one or more substrings such that the characters in each substring are unique. That is, no letter appears in a single substring more than once.
Return the minimum number of substrings in such a partition.
Note that each character should belong to exactly one substring in a partition.
Example 1:
Input: s = "abacaba"
Output: 4
Explanation:
Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
It can be shown that 4 is the minimum number of substrings needed.
Example 2:
Input: s = "ssssss"
Output: 6
Explanation:
The only valid partition is ("s","s","s","s","s","s").*/
class Solution {
public:
    int partitionString(string s) {
        int i = 0, j = 0, count = 1;
       set<char>mpp;
        while (j < s.size()){
             if (mpp.find(s[j]) == mpp.end()) { 
                mpp.insert(s[j]);
                j++;
                }
        else {
            count++;
               while (i < j  ) {
                    mpp.erase(s[i]);
                    i++;
                }
                mpp.insert(s[j]);
                j++;
        }
        
    }
    return count;
}
};
/*Maximum 69 Number
You are given a positive integer num consisting only of digits 6 and 9.
Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).
Example 1:
Input: num = 9669
Output: 9969
Explanation: 
Changing the first digit results in 6669.
Changing the second digit results in 9969.
Changing the third digit results in 9699.
Changing the fourth digit results in 9666.
The maximum number is 9969.
Example 2:
Input: num = 9996
Output: 9999
Explanation: Changing the last digit 6 to 9 results in the maximum number.
Example 3:
Input: num = 9999
Output: 9999
Explanation: It is better not to apply any change.*/
class Solution {
public:
    int maximum69Number (int num) {
        string temp = to_string(num);
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] == '6') { 
                temp[i] = '9'; 
                break; 
            }
        }
        return stoi(temp);
    }
};
/*Minimum Operations to Make the Array Increasing
You are given an integer array nums (0-indexed). In one operation, you can choose an element of the array and increment it by 1.
For example, if nums = [1,2,3], you can choose to increment nums[1] to make nums = [1,3,3].
Return the minimum number of operations needed to make nums strictly increasing.
An array nums is strictly increasing if nums[i] < nums[i+1] for all 0 <= i < nums.length - 1. An array of length 1 is trivially strictly increasing.
Example 1:
Input: nums = [1,1,1]
Output: 3
Explanation: You can do the following operations:
1) Increment nums[2], so nums becomes [1,1,2].
2) Increment nums[1], so nums becomes [1,2,2].
3) Increment nums[2], so nums becomes [1,2,3].
Example 2:
Input: nums = [1,5,2,4,1]
Output: 14
Example 3:
Input: nums = [8]
Output: 0*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count=0;
        int i=0;
        while(i<nums.size()-1){
            if(nums[i+1]<=nums[i]){
               count+=nums[i]-nums[i+1]+1;
               nums[i+1]+=nums[i]-nums[i+1]+1;
            }
            i++;
        }
        return count;
    }
};
