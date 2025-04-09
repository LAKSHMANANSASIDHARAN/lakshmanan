/* Largest Positive Integer That Exists With Its Negative
Given an integer array nums that does not contain any zeros, find the largest positive integer k such that -k also exists in the array.
Return the positive integer k. If there is no such integer, return -1.
Example 1:
Input: nums = [-1,2,-3,3]
Output: 3
Explanation: 3 is the only valid k we can find in the array.
Example 2:
Input: nums = [-1,10,6,7,-7,1]
Output: 7
Explanation: Both 1 and 7 have their corresponding negative values in the array. 7 has a larger value.
Example 3:
Input: nums = [-10,8,6,7,-2,-3]
Output: -1
Explanation: There is no a single valid k, we return -1.*/
class Solution {
public:
    int findMaxK(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int i=0,j=nums.size()-1;
       
       while(i<j){
           if (nums[i] + nums[j] == 0) return nums[j];
            else if (abs(nums[i]) < nums[j]) j--;
            else i++;
       }
       return -1;
         
    }
};
/* Split With Minimum Sum
Given a positive integer num, split it into two non-negative integers num1 and num2 such that:
The concatenation of num1 and num2 is a permutation of num.
In other words, the sum of the number of occurrences of each digit in num1 and num2 is equal to the number of occurrences of that digit in num.
num1 and num2 can contain leading zeros.
Return the minimum possible sum of num1 and num2.
Notes:
It is guaranteed that num does not contain any leading zeros.
The order of occurrence of the digits in num1 and num2 may differ from the order of occurrence of num.
Example 1:
Input: num = 4325
Output: 59
Explanation: We can split 4325 so that num1 is 24 and num2 is 35, giving a sum of 59. We can prove that 59 is indeed the minimal possible sum.
Example 2:
Input: num = 687
Output: 75
Explanation: We can split 687 so that num1 is 68 and num2 is 7, which would give an optimal sum of 75.*/
class Solution {
public:
    int splitNum(int num) {
       vector<int>temp;
       while(num){
        int last=num%10;
        temp.push_back(last);
        num/=10;
       } 
       sort(temp.begin(),temp.end());
       int evenPosNum = 0, oddPosNum = 0;
        for (int i = 0; i < temp.size(); i++) {
            if (i % 2 == 0) {
                evenPosNum = evenPosNum * 10 + temp[i];
            } else {
                oddPosNum = oddPosNum * 10 + temp[i];
            }
        }
        return evenPosNum+oddPosNum;
    }
       
};
