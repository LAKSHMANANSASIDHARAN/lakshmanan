/*Find the Difference of Two Arrays
Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:
answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
Note that the integers in the lists may be returned in any order.
Example 1:
Input: nums1 = [1,2,3], nums2 = [2,4,6]
Output: [[1,3],[4,6]]
Explanation:
For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums1. Therefore, answer[1] = [4,6].
Example 2:
Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
Output: [[3],[]]
Explanation:
For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
Every integer in nums2 is present in nums1. Therefore, answer[1] = [].*/
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
       unordered_map<int,int>num1,num2;
       for(int i=0;i<nums1.size();i++){
        num1[nums1[i]]++;
        
        }
         for(int i=0;i<nums2.size();i++){
        num2[nums2[i]]++;
        
        }
        vector<int>ans1,ans2;
       for(auto i:num1){
        if(num2.find(i.first)==num2.end()){
             ans1.push_back(i.first);
        }
       }
       for(auto i:num2){
        if(num1.find(i.first)==num1.end()){
             ans2.push_back(i.first);
        }
       }
        return {ans1,ans2};
    }
};
/* Find the XOR of Numbers Which Appear Twice
You are given an array nums, where each number in the array appears either once or twice.
Return the bitwise XOR of all the numbers that appear twice in the array, or 0 if no number appears twice.
Example 1:
Input: nums = [1,2,1,3]
Output: 1
Explanation:
The only number that appears twice in nums is 1.
Example 2:
Input: nums = [1,2,3]
Output: 0
Explanation:
No number appears twice in nums.
Example 3:
Input: nums = [1,2,2,1]
Output: 3
Explanation:
Numbers 1 and 2 appeared twice. 1 XOR 2 == 3.*/
class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
       vector<int>temp;
       unordered_map<int,int>mp;
       for(auto i:nums){
        mp[i]++;
       } 
       for(auto i:mp){
        if(i.second==2){
            temp.push_back(i.first);
        }
       }
    
       int count=0;
       for(auto i:temp) count^=i;
       return count;
    }
};
