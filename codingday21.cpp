/*Minimum Operations to Exceed Threshold Value II
You are given a 0-indexed integer array nums, and an integer k.
In one operation, you will:
Take the two smallest integers x and y in nums.
Remove x and y from nums.
Add min(x, y) * 2 + max(x, y) anywhere in the array.
Note that you can only apply the described operation if nums contains at least two elements.
Return the minimum number of operations needed so that all elements of the array are greater than or equal to k.
Example 1:
Input: nums = [2,11,10,1,3], k = 10
Output: 2
Explanation: In the first operation, we remove elements 1 and 2, then add 1 * 2 + 2 to nums. nums becomes equal to [4, 11, 10, 3].
In the second operation, we remove elements 3 and 4, then add 3 * 2 + 4 to nums. nums becomes equal to [10, 11, 10].
At this stage, all the elements of nums are greater than or equal to 10 so we can stop.
It can be shown that 2 is the minimum number of operations needed so that all elements of the array are greater than or equal to 10.
Example 2:
Input: nums = [1,1,2,4,9], k = 20
Output: 4
Explanation: After one operation, nums becomes equal to [2, 4, 9, 3].
After two operations, nums becomes equal to [7, 4, 9].
After three operations, nums becomes equal to [15, 9].
After four operations, nums becomes equal to [33].
At this stage, all the elements of nums are greater than 20 so we can stop.
It can be shown that 4 is the minimum number of operations needed so that all elements of the array are greater than or equal to 20.*/
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
       priority_queue<long long, vector<long long>, greater<>> pq(nums.begin(), nums.end());
        int ans=0;
        while(pq.top()<k){
            long long x=pq.top(); pq.pop();
            long long y=pq.top(); pq.pop();
            pq.push(2*x+y);
            ans++;
        }
        return ans;  
    }
};
/*Find the Number of Good Pairs I
You are given 2 integer arrays nums1 and nums2 of lengths n and m respectively. You are also given a positive integer k.
A pair (i, j) is called good if nums1[i] is divisible by nums2[j] * k (0 <= i <= n - 1, 0 <= j <= m - 1).
Return the total number of good pairs.
Example 1:
Input: nums1 = [1,3,4], nums2 = [1,3,4], k = 1
Output: 5
Explanation:
The 5 good pairs are (0, 0), (1, 0), (1, 1), (2, 0), and (2, 2).
Example 2:
Input: nums1 = [1,2,4,12], nums2 = [2,4], k = 3
Output: 2
Explanation:
The 2 good pairs are (3, 0) and (3, 1).*/
class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int count=0;
        int i=0;
        for(int i=0;i<nums2.size();i++){
            nums2[i]=nums2[i]*k;
        }
        for(int i=0;i<nums2.size();i++){
            for(int j=0;j<nums1.size();j++){
                  if(nums1[j]%nums2[i]==0){
                    count++;
                  }
            }
        }
        return count;
    }
};
