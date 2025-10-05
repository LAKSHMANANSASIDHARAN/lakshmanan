/*2395. Find Subarrays With Equal Sum
Given a 0-indexed integer array nums, determine whether there exist two subarrays of length 2 with equal sum. Note that the two subarrays must begin at different indices.
Return true if these subarrays exist, and false otherwise.
A subarray is a contiguous non-empty sequence of elements within an array.
Example 1:
Input: nums = [4,2,4]
Output: true
Explanation: The subarrays with elements [4,2] and [2,4] have the same sum of 6.
Example 2:
Input: nums = [1,2,3,4,5]
Output: false
Explanation: No two subarrays of size 2 have the same sum.
Example 3:
Input: nums = [0,0,0]
Output: true
Explanation: The subarrays [nums[0],nums[1]] and [nums[1],nums[2]] have the same sum of 0. 
Note that even though the subarrays have the same content, the two subarrays are considered different because they are in different positions in the original array.*/
class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int>st;
        for(int i=0;i<nums.size()-1;i++){
            int temp=nums[i]+nums[i+1];
            if(st.find(temp)!=st.end()) return true;
            else st.insert(temp);
        }
        return false;
    }
};
/*2475. Number of Unequal Triplets in Array
You are given a 0-indexed array of positive integers nums. Find the number of triplets (i, j, k) that meet the following conditions:
0 <= i < j < k < nums.length
nums[i], nums[j], and nums[k] are pairwise distinct.
In other words, nums[i] != nums[j], nums[i] != nums[k], and nums[j] != nums[k].
Return the number of triplets that meet the conditions.
Example 1:
Input: nums = [4,4,2,4,3]
Output: 3
Explanation: The following triplets meet the conditions:
- (0, 2, 4) because 4 != 2 != 3
- (1, 2, 4) because 4 != 2 != 3
- (2, 3, 4) because 2 != 4 != 3
Since there are 3 triplets, we return 3.
Note that (2, 0, 4) is not a valid triplet because 2 > 0.
Example 2:
Input: nums = [1,1,1,1,1]
Output: 0
Explanation: No triplets meet the conditions so we return 0.*/
class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int count=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            for(int j=i+1;j<nums.size()-1;j++){
                for(int k=j+1;k<nums.size();k++){
                    if(nums[i]!=nums[j] && nums[j]!=nums[k]) count++;
                }
            }
        }
        return count;
    }
};
