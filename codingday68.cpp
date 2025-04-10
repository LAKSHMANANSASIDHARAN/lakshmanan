/*Next Greater Element II
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.
The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.
Example 1:
Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.
Example 2:
Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n, -1);
        stack<int> st;
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }
            if (i < n) {
                temp[i] = st.empty() ? -1 : st.top();
            }
            st.push(nums[i % n]);
        }
        return temp;
    }
};
/*Next Greater Element I
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.
Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.
Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        vector<int>temp;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<nums2[i]){
                st.pop();
            }if(st.empty()){
               temp.push_back(-1);
            }
            else{
                temp.push_back(st.top());
            }
            st.push(nums2[i]);
        }
        reverse(temp.begin(),temp.end());
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            int j=0;
            while(j<nums2.size()){
                if(nums1[i]==nums2[j]){
                    ans.push_back(temp[j]);
                }
                j++;
            }
        }
        return ans;
    }
};
/*Maximum Product Subarray
Given an integer array nums, find a subarray that has the largest product, and return the product.
The test cases are generated so that the answer will fit in a 32-bit integer.
Example 1:
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int i=0;
        int maxi=nums[0];
        int temp=1;
        while(i<nums.size()){
            if(nums[i]==0){
               maxi=max(maxi,0);
               temp=1;
               i++;
            }
            else{
              temp*=nums[i];
              maxi=max(maxi,temp);
              i++;
            }
        }
        int n=nums.size()-1;
        int maxi2=nums[n];
        temp=1;
        i=n;
        while(i>=0){
           if(nums[i]==0){
               maxi2=max(maxi2,0);
               temp=1;
               i--;
            }
            else{
              temp*=nums[i];
              maxi2=max(maxi2,temp);
              i--;
            } 
        }
        return max(maxi,maxi2);
    }
};
/*Merge Intervals
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int n = intervals.size() - 1;
        int first = intervals[0][0], second = intervals[0][1];
        int i = 1;
        while (i <= n) {
            if (intervals[i][0] <= second) {
                second = max(second, intervals[i][1]);
            } else {
                ans.push_back({first, second});
                first = intervals[i][0];
                second = intervals[i][1];
            }
            i++;
        }
        ans.push_back({first, second});
        return ans;
    }
};
/* 4Sum
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.
Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();

        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int k = j + 1, l = n - 1;
                while (k < l) {
                    long long sum = 1LL * nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while (k < l && nums[k] == nums[k + 1])
                            ++k;
                        while (k < l && nums[l] == nums[l - 1])
                            --l;
                        ++k;
                        --l;
                    } else if (sum < target) {
                        ++k;
                    } else {
                        --l;
                    }
                }
            }
        }

        return ans;
    }
};
