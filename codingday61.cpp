/*Intersection of Two Arrays II
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.
Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
       vector<int>ans;
       unordered_map<int,int>mp;
       for(auto it:nums1){
        mp[it]++;
       }
       int i=0;
       while(i<nums2.size()){
        if(mp.find(nums2[i])!=mp.end() and mp[nums2[i]]!=0){
                ans.push_back(nums2[i]);
                mp[nums2[i]]--;
        }
        i++;
       }
        return ans;
    }
};
/*Reverse Vowels of a String
Given a string s, reverse only all the vowels in the string and return it.
The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.
Example 1:
Input: s = "IceCreAm"
Output: "AceCreIm"
Explanation:
The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".
Example 2:
Input: s = "leetcode"
Output: "leotcede"*/
class Solution {
    bool check(char& letter) {
        if (letter == 'a' or letter == 'e' or letter == 'i' or letter == 'o' or
            letter == 'u' or letter == 'A' or letter == 'E' or letter == 'I' or
            letter == 'O' or letter == 'U') {
            return true;
        }
        return false;
    }

public:
    string reverseVowels(string s) {
        int l = 0, r = s.size() - 1;
        while (l<r) {
           if(check(s[l]) && check(s[r])){
            swap(s[l],s[r]);
            l++;r--;
           }
           else if(check(s[l]) && !check(s[r])){
            r--;
           }
           else if(!check(s[l]) && check(s[r])){
               l++;
           }
           else{
            l++;r--;
           }

        }
        return s;
    }
};
/* Reverse String
Write a function that reverses a string. The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.
Example 1:
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]*/
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l=0,r=s.size()-1;
        while(l<=r){
            swap(s[l],s[r]);
            l++;r--;
        }
    }
};
/*Move Zeroes
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.
Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:
Input: nums = [0]
Output: [0]*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int l =0,r=0;
       while(r<nums.size()){
        if(nums[l]==0){
            while(r<nums.size() and nums[r]==0 ){
                r++;
            }
            if(r<nums.size()){
            swap(nums[l],nums[r]);
            }
            l++;
            r=l;
        }
        else{
            l++;r++;
        }
       } 
       
    }
};
/*Maximum Value of an Ordered Triplet I
You are given a 0-indexed integer array nums.
Return the maximum value over all triplets of indices (i, j, k) such that i < j < k. If all such triplets have a negative value, return 0.
The value of a triplet of indices (i, j, k) is equal to (nums[i] - nums[j]) * nums[k].
Example 1:
Input: nums = [12,6,1,2,7]
Output: 77
Explanation: The value of the triplet (0, 2, 4) is (nums[0] - nums[2]) * nums[4] = 77.
It can be shown that there are no ordered triplets of indices with a value greater than 77. 
Example 2:
Input: nums = [1,10,3,4,19]
Output: 133
Explanation: The value of the triplet (1, 2, 4) is (nums[1] - nums[2]) * nums[4] = 133.
It can be shown that there are no ordered triplets of indices with a value greater than 133.
Example 3:
Input: nums = [1,2,3]
Output: 0
Explanation: The only ordered triplet of indices (0, 1, 2) has a negative value of (nums[0] - nums[1]) * nums[2] = -3. Hence, the answer would be 0.*/
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) { 
                for (int k = j + 1; k < n; k++) {
                    ans = max(ans, (long long)(nums[i] - nums[j]) * nums[k]);
                }
            }
        }
        return ans;
    }
};
