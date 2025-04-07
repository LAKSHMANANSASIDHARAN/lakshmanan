/*Maximum Average Subarray I
You are given an integer array nums consisting of n elements, and an integer k.
Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.
Example 1:
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
Example 2:
Input: nums = [5], k = 1
Output: 5.00000*/
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i = 0, j = 0;
        double ans = 0, res = 0;
        double maxi = INT_MIN;

        while (j < nums.size()) {
            ans += nums[j];
            if (j - i + 1 == k) {
                res = ans / k;
                maxi = max(maxi, res);
                ans -= nums[i];
                i++;
            }
            j++;
        }
        return maxi;
    }
};
/*Find the K-Beauty of a Number
The k-beauty of an integer num is defined as the number of substrings of num when it is read as a string that meet the following conditions:
It has a length of k.
It is a divisor of num.
Given integers num and k, return the k-beauty of num.
Note:
Leading zeros are allowed.
0 is not a divisor of any value.
A substring is a contiguous sequence of characters in a string.
Example 1:
Input: num = 240, k = 2
Output: 2
Explanation: The following are the substrings of num of length k:
- "24" from "240": 24 is a divisor of 240.
- "40" from "240": 40 is a divisor of 240.
Therefore, the k-beauty is 2.
Example 2:
Input: num = 430043, k = 2
Output: 2
Explanation: The following are the substrings of num of length k:
- "43" from "430043": 43 is a divisor of 430043.
- "30" from "430043": 30 is not a divisor of 430043.
- "00" from "430043": 0 is not a divisor of 430043.
- "04" from "430043": 4 is not a divisor of 430043.
- "43" from "430043": 43 is a divisor of 430043.
Therefore, the k-beauty is 2.*/
class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int i = 0, j = 0, count = 0;
        string tempp = "";

        while (j < s.size()) {
            tempp += s[j];
            if (j - i + 1 == k) {
                int val = stoi(tempp);
                if (val != 0 && num % val == 0) {
                    count++;
                }
                tempp.erase(0, 1);
                i++;
            }
            j++;
        }
        return count;
    }
};
