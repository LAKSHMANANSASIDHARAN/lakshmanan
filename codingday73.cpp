/*Median of Two Sorted Arrays
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).
Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double> temp;
        for (auto it : nums1) temp.push_back(it);
        for (auto it : nums2) temp.push_back(it);
        
        sort(temp.begin(), temp.end());
        int mid = temp.size() / 2;

        if (temp.size() % 2 != 0) {
            return temp[mid];
        }

        double res = temp[mid] + temp[mid - 1];
        return res / 2;
    }
};
