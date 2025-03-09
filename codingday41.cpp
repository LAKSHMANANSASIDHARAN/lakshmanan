/*Binary Subarrays With Sum
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
A subarray is a contiguous part of the array.
Example 1:
Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:
Input: nums = [0,0,0,0,0], goal = 0
Output: 15*/
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int i = 0;
        int count = 0;
        int sum = 0;
        while (i < nums.size()) {
            sum += nums[i];

            if (mpp.find(sum - goal) != mpp.end()) {
                count += mpp[sum - goal];
            }
            mpp[sum]++;
            i++;
        }
        return count;
    }
};
