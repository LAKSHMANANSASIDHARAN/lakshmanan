/*2762. Continuous Subarrays

You are given a 0-indexed integer array nums. A subarray of nums is called continuous if:

Let i, i + 1, ..., j be the indices in the subarray. Then, for each pair of indices i <= i1, i2 <= j, 0 <= |nums[i1] - nums[i2]| <= 2.
Return the total number of continuous subarrays.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [5,4,2,4]
Output: 8
Explanation: 
Continuous subarray of size 1: [5], [4], [2], [4].
Continuous subarray of size 2: [5,4], [4,2], [2,4].
Continuous subarray of size 3: [4,2,4].
There are no subarrys of size 4.
Total continuous subarrays = 4 + 3 + 1 = 8.
It can be shown that there are no more continuous subarrays.
 

Example 2:

Input: nums = [1,2,3]
Output: 6
Explanation: 
Continuous subarray of size 1: [1], [2], [3].
Continuous subarray of size 2: [1,2], [2,3].
Continuous subarray of size 3: [1,2,3].
Total continuous subarrays = 3 + 2 + 1 = 6.
 */
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        deque<int> minDeque, maxDeque;
        long long ans = 0;
        int left = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            while (!minDeque.empty() && nums[right] < minDeque.back()) minDeque.pop_back();
            while (!maxDeque.empty() && nums[right] > maxDeque.back()) maxDeque.pop_back();
            minDeque.push_back(nums[right]);
            maxDeque.push_back(nums[right]);
            
            while (!minDeque.empty() && !maxDeque.empty() && maxDeque.front() - minDeque.front() > 2) {
                if (minDeque.front() == nums[left]) minDeque.pop_front();
                if (maxDeque.front() == nums[left]) maxDeque.pop_front();
                left++;
            }
            
            ans += right - left + 1;
        }
        
        return ans;
    }
};
