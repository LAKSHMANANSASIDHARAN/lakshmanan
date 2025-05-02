/* Max Consecutive Ones
Given a binary array nums, return the maximum number of consecutive 1's in the array.
Example 1:
Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
Example 2:
Input: nums = [1,0,1,1,0,1]
Output: 2
 */ 
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0,count=0,res=0;
        while(i<nums.size()){
            if(nums[i]==1){
                count++;
            }
            else{
                res=max(res,count);
                count=0;
                }
                i++;
            }
              res = max(res, count);
        
        return res;
    }
};
/*Single Number
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.
Example 1:
Input: nums = [2,2,1]
Output: 1
Example 2:
Input: nums = [4,1,2,1,2]
Output: 4
Example 3:
Input: nums = [1]
Output: 1
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++){
            res^=nums[i];
        }
        return res;
    }
};
