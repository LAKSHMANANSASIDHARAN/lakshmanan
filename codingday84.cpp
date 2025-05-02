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
/*Plus One
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.
Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
Example 2:
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
Example 3:
Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        vector<int>ans;
        int temp=digits[digits.size()-1]+1;
        if(temp<10){
         digits[digits.size()-1]=temp;
         return digits;
         }
       
         ans.push_back(0);
        for(int i=digits.size()-2;i>=0;i--){
            if(carry==0){
             ans.push_back(digits[i]);
            }
            else{
                int res=digits[i]+carry;
                if(res==10){
                   ans.push_back(0);
                 }
                else {
    ans.push_back(res);
    carry = 0;
}

            }
        }
        if(carry==1){
            ans.push_back(1);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
