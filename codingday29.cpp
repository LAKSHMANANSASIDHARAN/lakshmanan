/* The Two Sneaky Numbers of Digitville
In the town of Digitville, there was a list of numbers called nums containing integers from 0 to n - 1. Each number was supposed to appear exactly once in the list, however, two mischievous numbers sneaked in an additional time, making the list longer than usual.
As the town detective, your task is to find these two sneaky numbers. Return an array of size two containing the two numbers (in any order), so peace can return to Digitville.
Example 1:
Input: nums = [0,1,1,0]
Output: [0,1]
Explanation:
The numbers 0 and 1 each appear twice in the array.
Example 2:
Input: nums = [0,3,2,1,3,2]
Output: [2,3]
Explanation:
The numbers 2 and 3 each appear twice in the array.
Example 3:
Input: nums = [7,1,5,4,3,4,6,0,9,5,8,2]
Output: [4,5]
Explanation:
The numbers 4 and 5 each appear twice in the array.*/
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
     unordered_map<int,int>mpp;
     vector<int>ans;
     for(auto it:nums){
        mpp[it]++;
     }   
     for(auto &[f,l]:mpp){
        if(l>=2){
            ans.push_back(f);
        }
     }
     return ans;
    }
};
/*Count Partitions with Even Sum Difference
You are given an integer array nums of length n.
A partition is defined as an index i where 0 <= i < n - 1, splitting the array into two non-empty subarrays such that:
Left subarray contains indices [0, i].
Right subarray contains indices [i + 1, n - 1].
Return the number of partitions where the difference between the sum of the left and right subarrays is even.
Example 1:
Input: nums = [10,10,3,7,6]
Output: 4
Explanation:
The 4 partitions are:
[10], [10, 3, 7, 6] with a sum difference of 10 - 26 = -16, which is even.
[10, 10], [3, 7, 6] with a sum difference of 20 - 16 = 4, which is even.
[10, 10, 3], [7, 6] with a sum difference of 23 - 13 = 10, which is even.
[10, 10, 3, 7], [6] with a sum difference of 30 - 6 = 24, which is even.
Example 2:
Input: nums = [1,2,2]
Output: 0
Explanation:
No partition results in an even sum difference.
Example 3:
Input: nums = [2,4,6,8]
Output: 3
Explanation:
All partitions result in an even sum difference*/
class Solution {
public:
    int countPartitions(vector<int>& arr) {
       int Total_Sum=0;
        int sum = 0;
        for (int it : arr) {
           Total_Sum+=it;
        }
        int i = 0;
        int count = 0;
        int leftSum=0;
        while (i < arr.size() - 1) {
              leftSum += arr[i];
            if ((Total_Sum - leftSum - leftSum) % 2 == 0) {
                count++;
        }
        i++;
        }
        return count;
    }
};
/*Sum of All Odd Length Subarrays
Given an array of positive integers arr, return the sum of all possible odd-length subarrays of arr.
A subarray is a contiguous subsequence of the array.
Example 1:
Input: arr = [1,4,2,5,3]
Output: 58
Explanation: The odd-length subarrays of arr and their sums are:
[1] = 1
[4] = 4
[2] = 2
[5] = 5
[3] = 3
[1,4,2] = 7
[4,2,5] = 11
[2,5,3] = 10
[1,4,2,5,3] = 15
If we add all these together we get 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
Example 2:
Input: arr = [1,2]
Output: 3
Explanation: There are only 2 subarrays of odd length, [1] and [2]. Their sum is 3.
Example 3:
Input: arr = [10,11,12]
Output: 66*/
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        vector<int> temp;
        long long Total_Sum = 0;  // Changed to long long to prevent overflow

        for (int it : arr) {
            Total_Sum += it;
            temp.push_back(Total_Sum);
        }

        int i = 2;
        while (i < temp.size()) {
            int k = 0;  // Reset k for each new subarray length
            
            for (int j = i; j < temp.size(); j++) {
                if (j == i) {
                    Total_Sum += temp[j];
                } else {
                    Total_Sum += (temp[j] - temp[k]);
                    k++;
                }
            }
            i = i + 2;
        }
        return Total_Sum;
    }
};
/*Maximum Length Substring With Two Occurrences
Given a string s, return the maximum length of a 
substring
such that it contains at most two occurrences of each character.
 Example 1:
Input: s = "bcbbbcba"
Output: 4
Explanation:
The following substring has a length of 4 and contains at most two occurrences of each character: "bcbbbcba".
Example 2:
Input: s = "aaaa"
Output: 2
Explanation:
The following substring has a length of 2 and contains at most two occurrences of each character: "aaaa".*/
class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> mpp;
        int i = 0;
        int j = 0;
        int maxi = 0;
        while (j < s.size()) {
            if (mpp[s[j]] < 2) {
                mpp[s[j]]++;
                maxi = max(j - i + 1, maxi);

                j++;

            } else {

                mpp[s[i]]--;
                i++;
                maxi = max(j - i + 1, maxi);
            }
        }
        return  maxi;
    }
};
