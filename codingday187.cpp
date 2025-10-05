/*2395. Find Subarrays With Equal Sum
Given a 0-indexed integer array nums, determine whether there exist two subarrays of length 2 with equal sum. Note that the two subarrays must begin at different indices.
Return true if these subarrays exist, and false otherwise.
A subarray is a contiguous non-empty sequence of elements within an array.
Example 1:
Input: nums = [4,2,4]
Output: true
Explanation: The subarrays with elements [4,2] and [2,4] have the same sum of 6.
Example 2:
Input: nums = [1,2,3,4,5]
Output: false
Explanation: No two subarrays of size 2 have the same sum.
Example 3:
Input: nums = [0,0,0]
Output: true
Explanation: The subarrays [nums[0],nums[1]] and [nums[1],nums[2]] have the same sum of 0. 
Note that even though the subarrays have the same content, the two subarrays are considered different because they are in different positions in the original array.*/
class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int>st;
        for(int i=0;i<nums.size()-1;i++){
            int temp=nums[i]+nums[i+1];
            if(st.find(temp)!=st.end()) return true;
            else st.insert(temp);
        }
        return false;
    }
};
/*2475. Number of Unequal Triplets in Array
You are given a 0-indexed array of positive integers nums. Find the number of triplets (i, j, k) that meet the following conditions:
0 <= i < j < k < nums.length
nums[i], nums[j], and nums[k] are pairwise distinct.
In other words, nums[i] != nums[j], nums[i] != nums[k], and nums[j] != nums[k].
Return the number of triplets that meet the conditions.
Example 1:
Input: nums = [4,4,2,4,3]
Output: 3
Explanation: The following triplets meet the conditions:
- (0, 2, 4) because 4 != 2 != 3
- (1, 2, 4) because 4 != 2 != 3
- (2, 3, 4) because 2 != 4 != 3
Since there are 3 triplets, we return 3.
Note that (2, 0, 4) is not a valid triplet because 2 > 0.
Example 2:
Input: nums = [1,1,1,1,1]
Output: 0
Explanation: No triplets meet the conditions so we return 0.*/
class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int count=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            for(int j=i+1;j<nums.size()-1;j++){
                for(int k=j+1;k<nums.size();k++){
                    if(nums[i]!=nums[j] && nums[j]!=nums[k]) count++;
                }
            }
        }
        return count;
    }
};
/*1329. Sort the Matrix Diagonally
A matrix diagonal is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until reaching the matrix's end. For example, the matrix diagonal starting from mat[2][0], where mat is a 6 x 3 matrix, includes cells mat[2][0], mat[3][1], and mat[4][2].
Given an m x n matrix mat of integers, sort each matrix diagonal in ascending order and return the resulting matrix.
Example 1:
Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]
Example 2:
Input: mat = [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]
Output: [[5,17,4,1,52,7],[11,11,25,45,8,69],[14,23,25,44,58,15],[22,27,31,36,50,66],[84,28,75,33,55,68]]*/
class Solution {
    vector<int>process(int i, int j, vector<vector<int>>& nums){
        vector<int>temp;
        while(i<nums.size() && j<nums[0].size()){
         temp.push_back(nums[i][j]);
         i++;
         j++;
        }
        sort(temp.begin(),temp.end());
        return temp;
    }
    void correct(vector<int>&temp, int i, int j,vector<vector<int>>& nums){
        int ind=0;
         while(i<nums.size() && j<nums[0].size()){
         nums[i][j]=temp[ind];
         i++;
         j++;
         ind++;
        }
    }
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        for(int i=0;i<mat.size();i++){
           vector<int>temp= process(i,0,mat);
           correct(temp,i,0,mat);
        }
        for(int i=1;i<mat[0].size();i++){
            vector<int>temp= process(0,i,mat);
           correct(temp,0,i,mat);
        }
        return mat;
    }
};
