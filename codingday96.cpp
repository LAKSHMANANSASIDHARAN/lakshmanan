/*Minimum Array Length After Pair Removals
Given an integer array num sorted in non-decreasing order.
You can perform the following operation any number of times:
Choose two indices, i and j, where nums[i] < nums[j].
Then, remove the elements at indices i and j from nums. The remaining elements retain their original order, and the array is re-indexed.
Return the minimum length of nums after applying the operation zero or more times.
Example 1:
Input: nums = [1,2,3,4]
Output: 0
Example 2:
Input: nums = [1,1,2,2,3,3]
Output: 0
Example 3:
Input: nums = [1000000000,1000000000]
Output: 2
Since both numbers are equal, they cannot be removed.
Example 4:
Input: nums = [2,3,4,4,4]
Output: 1*/
class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
       priority_queue<int> maxHeap;
       priority_queue<int, vector<int>, greater<int>> minHeap;
       unordered_map<int,int>mp;
       for(auto it:nums){
        mp[it]++;
       }
       for(auto &[f,s]:mp){
        maxHeap.push(s);
        minHeap.push(s);
       }
       while(maxHeap.size() > 1){
         int a = maxHeap.top(); maxHeap.pop();
         int b = maxHeap.top(); maxHeap.pop();
        a--; b--;
            if (a > 0) maxHeap.push(a);
            if (b > 0) maxHeap.push(b);
       }
           if (!maxHeap.empty()) return maxHeap.top();
        return 0;
    }
};
