/*Count Special Quadruplets
Given a 0-indexed integer array nums, return the number of distinct quadruplets (a, b, c, d) such that:
nums[a] + nums[b] + nums[c] == nums[d], and
a < b < c < d
Example 1:
Input: nums = [1,2,3,6]
Output: 1
Explanation: The only quadruplet that satisfies the requirement is (0, 1, 2, 3) because 1 + 2 + 3 == 6.
Example 2:
Input: nums = [3,3,6,4,5]
Output: 0
Explanation: There are no such quadruplets in [3,3,6,4,5].
Example 3:
Input: nums = [1,1,1,3,5]
Output: 4
Explanation: The 4 quadruplets that satisfy the requirement are:
- (0, 1, 2, 3): 1 + 1 + 1 == 3
- (0, 1, 3, 4): 1 + 1 + 3 == 5
- (0, 2, 3, 4): 1 + 1 + 3 == 5
- (1, 2, 3, 4): 1 + 1 + 3 == 5*/
class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
       int count=0;
    
for (int a = 0; a < nums.size() - 3; a++) {
    for (int b = a + 1; b < nums.size() - 2; b++) {
        for (int c = b + 1; c < nums.size() - 1; c++) {
            for (int d = c + 1; d < nums.size(); d++) {
                if (nums[a] + nums[b] + nums[c] == nums[d]) {
                    count++;
                }
            }
        }
    }
} return count;
    }
};
/* Sqrt(x)
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
You must not use any built-in exponent function or operator.
For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 Example 1:
Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.*/
class Solution {
public:
    int mySqrt(int x) {
        int start=1,end=x;
        int res=0;
        while(start<=end){
       int mid = start + (end - start) / 2;
    long long temp = 1LL * mid * mid;

          if(temp<=x){
            res=mid;
            start=mid+1;

          }
          else if(temp>x){
            end=mid-1;
            }
        }
        return res;
    }
};
/*First Bad Version
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.
Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
Example 1:
Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.
Example 2:
Input: n = 1, bad = 1
Output: 1
 */
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left=1,right=n;
        int res=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(isBadVersion(mid)){
                res=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return res;
    }
};
/*Valid Perfect Square
Given a positive integer num, return true if num is a perfect square or false otherwise.
A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.
You must not use any built-in library function, such as sqrt.
Example 1:
Input: num = 16
Output: true
Explanation: We return true because 4 * 4 = 16 and 4 is an integer.
Example 2:
Input: num = 14
Output: false
Explanation: We return false because 3.742 * 3.742 = 14 and 3.742 is not an integer.*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        int left=1,right=num;
        while(left<=right){
            int mid=left+(right-left)/2;
            long long temp=1LL * mid * mid;
            if(temp==num){
                return true;
            }
            else if(temp<num){
                left=mid+1;
            }
            else{
                right=mid-1;
            }

        }
        return false;
    }
};
/*Search in Rotated Sorted Array II
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).
Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].
Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.
You must decrease the overall operation steps as much as possible.
Example 1:
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:
Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
 */
class Solution {
  public:
    bool search(vector<int>& nums, int target) {
       for(int i=0;i<nums.size();i++){
        if(nums[i]==target){
            return true;
        }
       }
       return false;
    }
};
