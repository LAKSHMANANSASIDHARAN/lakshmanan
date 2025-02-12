/* Max Sum of a Pair With Equal Sum of Digits
You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].
Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.
Example 1:
Input: nums = [18,43,36,13,7]
Output: 54
Explanation: The pairs (i, j) that satisfy the conditions are:
- (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
- (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
So the maximum sum that we can obtain is 54.
Example 2:
Input: nums = [10,12,19,14]
Output: -1
Explanation: There are no two numbers that satisfy the conditions, so we return -1.*/
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        sort(arr.rbegin(), arr.rend());
        unordered_map<int, vector<int>> mpp;

        for (int i = 0; i < arr.size(); i++) {
            int key = finding(arr[i]);
            mpp[key].push_back(arr[i]);
        }

        int maxi = 0;
        for (auto& [key, value] : mpp) {
            if (value.size() > 1) {
                int sum = value[0] + value[1];
                maxi = max(maxi, sum);
            }
        }
       if(maxi==0){ return -1;}
        return maxi;
    }

private:
    int finding(int n) {
        int t, s;
        t = 0;
        s = 0;
        while (n > 0) {
            t = n % 10;
            s += t;
            n = n / 10;
        }
        return s;
    }
};
