/*Monotonic Array
An array is monotonic if it is either monotone increasing or monotone decreasing.
An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].
Given an integer array nums, return true if the given array is monotonic, or false otherwise.
Example 1:
Input: nums = [1,2,2,3]
Output: true
Example 2:
Input: nums = [6,5,4,4]
Output: true
Example 3:
Input: nums = [1,3,2]
Output: false
 */
class Solution {
    bool small(vector<int>&nums ,int i){
        
        while(i<nums.size()-1){
            if(nums[i]>nums[i+1]){
                return false;
            }
            i++;
        }
        return true;
    }
     bool big(vector<int>&nums, int i){
        
        while(i<nums.size()-1){
            if(nums[i]<nums[i+1]){
                return false;
            }
            i++;
        }
        return true;
    }

public:
    bool isMonotonic(vector<int>& nums) {
       for(int i=0;i<nums.size()-1;i++){
        if(nums[i]==nums[i+1]){
            continue;
        }
        else if(nums[i]<nums[i+1]){
            return small(nums,i);
        }else{
            return big(nums,i);
        }
       }
       return true;
    }
};
/*Valid Mountain Array
Given an array of integers arr, return true if and only if it is a valid mountain array.
Recall that arr is a mountain array if and only if:
arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Example 1:
Input: arr = [2,1]
Output: false
Example 2:
Input: arr = [3,5,5]
Output: false
Example 3:
Input: arr = [0,3,2,1]
Output: true*/
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3){
            return false;
        }
       int i=1;
       bool ch=false;
       while(i<arr.size()-1){
        if(arr[i]>arr[i-1]&&arr[i]>arr[i+1]){
            ch=true;
          break;
        }
       
        i++;
       }
       if(!ch){
        return false;
       }
       int left=i-1,right=i+1;
       while(left>=0){
        if(arr[left]>=arr[left+1]){
            return false;
        }
        left--;
       }
       while(right<arr.size()){
         if(arr[right]>=arr[right-1]){
            return false;
        }
        right++;
       }
       return true;
    }
};
