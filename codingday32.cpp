/* Number of Arithmetic Triplets
You are given a 0-indexed, strictly increasing integer array nums and a positive integer diff. A triplet (i, j, k) is an arithmetic triplet if the following conditions are met:
i < j < k,
nums[j] - nums[i] == diff, and
nums[k] - nums[j] == diff.
Return the number of unique arithmetic triplets.
Example 1:
Input: nums = [0,1,4,6,7,10], diff = 3
Output: 2
Explanation:
(1, 2, 4) is an arithmetic triplet because both 7 - 4 == 3 and 4 - 1 == 3.
(2, 4, 5) is an arithmetic triplet because both 10 - 7 == 3 and 7 - 4 == 3. 
Example 2:
Input: nums = [4,5,6,7,8,9], diff = 2
Output: 2
Explanation:
(0, 2, 4) is an arithmetic triplet because both 8 - 6 == 2 and 6 - 4 == 2.
(1, 3, 5) is an arithmetic triplet because both 9 - 7 == 2 and 7 - 5 == 2.*/
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int i = 0, j = 1;
   int count = 0;
   while (j < nums.size()) {  
       if (nums[j] - nums[i] == diff) {
           int k = j + 1;
           while (k < nums.size()) {
               if (nums[k] - nums[j] == diff) {
                   count++;
                   break;
               } 
               else if (nums[k] - nums[j] > diff) {
                   break;
               }
               k++;
           }
           j++;  
       } 
       else if (nums[j] - nums[i] < diff) {
           j++;
       } 
       else {
           i++;
           if (i == j) j++;  
       }
   }
   return  count;  
    }
};
/*Count Number of Pairs With Absolute Difference K
Given an integer array nums and an integer k, return the number of pairs (i, j) where i < j such that |nums[i] - nums[j]| == k.
The value of |x| is defined as:
x if x >= 0.
-x if x < 0.
 Example 1:
Input: nums = [1,2,2,1], k = 1
Output: 4
Explanation: The pairs with an absolute difference of 1 are:
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]
Example 2:
Input: nums = [1,3], k = 3
Output: 0
Explanation: There are no pairs with an absolute difference of 3.
Example 3:
Input: nums = [3,2,1,5,4], k = 2
Output: 3
Explanation: The pairs with an absolute difference of 2 are:
- [3,2,1,5,4]
- [3,2,1,5,4]
- [3,2,1,5,4]*/
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for (auto it : nums) {
            mpp[it]++;
        }
        int count = 0;
        for (auto& [f, s] : mpp) {
            if (mpp.count(f + k)) {
                count += s * mpp[f + k];  
            }
        }
        return count;
    }
};
