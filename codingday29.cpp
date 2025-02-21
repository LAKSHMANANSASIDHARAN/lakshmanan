/* The Two Sneaky Numbers of Digitville
In the town of Digitville, there was a list of numbers called nums containing integers from 0 to n - 1. Each number was supposed to appear exactly once in the list, however, two mischievous numbers sneaked in an additional time, making the list longer than usual.
As the town detective, your task is to find these two sneaky numbers. Return an array of size two containing the two numbers (in any order), so peace can return to Digitville.
Example 1:
Input: nums = [0,1,1,0]
Output: [0,1]
Explanation:
The numbers 0 and 1 each appear twice in the array.
Example 2:
Input: nums = [0,3,2,1,3,2]
Output: [2,3]
Explanation:
The numbers 2 and 3 each appear twice in the array.
Example 3:
Input: nums = [7,1,5,4,3,4,6,0,9,5,8,2]
Output: [4,5]
Explanation:
The numbers 4 and 5 each appear twice in the array.*/
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
     unordered_map<int,int>mpp;
     vector<int>ans;
     for(auto it:nums){
        mpp[it]++;
     }   
     for(auto &[f,l]:mpp){
        if(l>=2){
            ans.push_back(f);
        }
     }
     return ans;
    }
};
/*Count Partitions with Even Sum Difference
You are given an integer array nums of length n.
A partition is defined as an index i where 0 <= i < n - 1, splitting the array into two non-empty subarrays such that:
Left subarray contains indices [0, i].
Right subarray contains indices [i + 1, n - 1].
Return the number of partitions where the difference between the sum of the left and right subarrays is even.
Example 1:
Input: nums = [10,10,3,7,6]
Output: 4
Explanation:
The 4 partitions are:
[10], [10, 3, 7, 6] with a sum difference of 10 - 26 = -16, which is even.
[10, 10], [3, 7, 6] with a sum difference of 20 - 16 = 4, which is even.
[10, 10, 3], [7, 6] with a sum difference of 23 - 13 = 10, which is even.
[10, 10, 3, 7], [6] with a sum difference of 30 - 6 = 24, which is even.
Example 2:
Input: nums = [1,2,2]
Output: 0
Explanation:
No partition results in an even sum difference.
Example 3:
Input: nums = [2,4,6,8]
Output: 3
Explanation:
All partitions result in an even sum difference*/
class Solution {
public:
    int countPartitions(vector<int>& arr) {
       int Total_Sum=0;
        int sum = 0;
        for (int it : arr) {
           Total_Sum+=it;
        }
        int i = 0;
        int count = 0;
        int leftSum=0;
        while (i < arr.size() - 1) {
              leftSum += arr[i];
            if ((Total_Sum - leftSum - leftSum) % 2 == 0) {
                count++;
        }
        i++;
        }
        return count;
    }
};
