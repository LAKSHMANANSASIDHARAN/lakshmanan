/* Contiguous Array
Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
Example 1:
Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
Example 2:
Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Example 3:
Input: nums = [0,1,1,1,1,1,0,0,0]
Output: 6
Explanation: [1,1,1,0,0,0] is the longest contiguous subarray with equal number of 0 and 1.*/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       unordered_map<int, int> mp;
        mp[0] = -1;  
        int maxLen = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] == 0) ? -1 : 1;
            if (mp.find(sum) != mp.end()) {
                maxLen = max(maxLen, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }
        return maxLen;
    }
};
/*Continuous Subarray Sum
Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.
A good subarray is a subarray where:
its length is at least two, and
the sum of the elements of the subarray is a multiple of k.
Note that:
A subarray is a contiguous part of the array.
An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.
Example 1:
Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
Example 2:
Input: nums = [23,2,6,4,7], k = 6
Output: true
Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
Example 3:
Input: nums = [23,2,6,4,7], k = 13
Output: false*/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> temp;
        temp.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            int sum = temp[i - 1] + nums[i];
            temp.push_back(sum);
        }
        unordered_set<int> check;
        for (int i = 1; i < temp.size(); i++) {
            if (temp[i] % k == 0 || check.find(temp[i] % k) != check.end()) {
                return true;
            }
            check.insert(temp[i - 1] % k);
        }
        return false;
    }
};
