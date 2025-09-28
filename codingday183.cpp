/*74. Search a 2D Matrix
You are given an m x n integer matrix matrix with the following two properties:
Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.
You must write a solution in O(log(m * n)) time complexity.
Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false*/
class Solution {
    bool check(vector<int>&arr,int & target){
        int l=0,r=arr.size()-1;
        while(l<=r){
            int m=(l+r)/2;
            if(arr[m]<target){
                l=m+1;
            }
            else if(arr[m]>target){
               r=m-1;
            }
            else return true;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto arr:matrix){
        if(check(arr,target)) return true;
       }
       return false; 
    }
};
/*153. Find Minimum in Rotated Sorted Array
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
Given the sorted rotated array nums of unique elements, return the minimum element of this array.
You must write an algorithm that runs in O(log n) time.
Example 1:
Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
Example 2:
Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
Example 3:
Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times. */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        int temp=INT_MAX;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[left]<nums[mid] && nums[mid]>nums[right]){
                if(nums[right]>nums[left]){
                     temp=min(temp,nums[left]);
                     right=mid-1;
                } 
               else {
                temp=min(temp,nums[right]);
                left=mid+1;
               }
            }
            else if(nums[left]>nums[mid] && nums[mid]<nums[right]){
                temp=min(temp,nums[mid]);
                if(nums[left]<nums[right]) left=mid+1;
                else right=mid-1;
            }
            else if(nums[left]<=nums[mid] or nums[mid]>=nums[right]){
                if(nums[right]<nums[left]){
                    temp=min(temp,nums[right]);
                    left=mid+1;
                }
                else {
                    temp=min(temp,nums[left]);
                    right=mid-1;
                }
            }
        }
        return temp;
    }
};
