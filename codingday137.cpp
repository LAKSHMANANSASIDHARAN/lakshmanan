/*Maximum Product of Three Numbers
Given an integer array nums, find three numbers whose product is maximum and return the maximum product.
Example 1:
Input: nums = [1,2,3]
Output: 6
Example 2:
Input: nums = [1,2,3,4]
Output: 24
Example 3:
Input: nums = [-1,-2,-3]
Output: -6*/
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int one,two,three;
     int n=nums.size()-1;
       two= nums[0]*nums[1]*nums[n];
         three= nums[n]*nums[n-1]*nums[n-2];
   
    return max(two,three);

    }
};
