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
/**/
/**/
/**/
