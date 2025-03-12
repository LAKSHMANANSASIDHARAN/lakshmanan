/*Maximum Erasure Value
You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.
Return the maximum score you can get by erasing exactly one subarray.
An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).
Example 1:
Input: nums = [4,2,4,5,6]
Output: 17
Explanation: The optimal subarray here is [2,4,5,6].
Example 2:
Input: nums = [5,2,1,2,5,2,1,2,5]
Output: 8
Explanation: The optimal subarray here is [5,2,1] or [1,2,5].*/
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int maxi = 0;
        int left = 0, right = 0;
        int sum = 0;

        while (right < nums.size()) {
            if (mpp.find(nums[right]) != mpp.end()) {
                while (left <= mpp[nums[right]] and left <= right) {
                    sum -= nums[left];
                    left++;
                }
            }

            sum += nums[right];
            mpp[nums[right]] = right;
            right++;

            maxi = max(sum, maxi);
        }
        return maxi;
    }
};
