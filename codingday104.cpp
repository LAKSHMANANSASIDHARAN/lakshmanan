/*Pow(x, n)
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
Example 1:
Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:
Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25*/
class Solution {
public:
    double myPow(double x, int n) {
        double output = 1;
        long long power = n;
        if (power < 0) {
            x = 1 / x;
            power = -power;
        }
        while (power > 0) {
            if (power % 2 == 1) {
                output *= x;
            }
            x *= x;
            power /= 2;
        }
        return output;
    }
};
/* Find the Longest Equal Subarray
You are given a 0-indexed integer array nums and an integer k.
A subarray is called equal if all of its elements are equal. Note that the empty subarray is an equal subarray.
Return the length of the longest possible equal subarray after deleting at most k elements from nums.
A subarray is a contiguous, possibly empty sequence of elements within an array.
Example 1:
Input: nums = [1,3,2,3,1,3], k = 3
Output: 3
Explanation: It's optimal to delete the elements at index 2 and index 4.
After deleting them, nums becomes equal to [1, 3, 3, 3].
The longest equal subarray starts at i = 1 and ends at j = 3 with length equal to 3.
It can be proven that no longer equal subarrays can be created.
Example 2:
Input: nums = [1,1,2,2,1,1], k = 2
Output: 4
Explanation: It's optimal to delete the elements at index 2 and index 3.
After deleting them, nums becomes equal to [1, 1, 1, 1].
The array itself is an equal subarray, so the answer is 4.
It can be proven that no longer equal subarrays can be created.*/
class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
   unordered_map<int, vector<int>> arr;
    for (int i = 0; i < nums.size(); i++) {
        arr[nums[i]].push_back(i);
    }
    int maxi = 0;
    for (auto i : arr) {
        vector<int> temp = i.second;
        int l = 0, r = 0;
        int freq = 0;
        while (r < temp.size() && l <= r) {
            freq = r - l + 1;
            int len = temp[r] - temp[l] + 1;
            int nonlen = len - freq;
            if (nonlen <= k) {
                if (freq > maxi) maxi = freq;
                r++;
            } else {
                l++;
            }
        }
    }
    return maxi;
    }
};
