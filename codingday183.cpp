/*74. Search a 2D Matrix
You are given an m x n integer matrix matrix with the following two properties:
Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.
You must write a solution in O(log(m * n)) time complexity.
Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false*/
class Solution {
    bool check(vector<int>&arr,int & target){
        int l=0,r=arr.size()-1;
        while(l<=r){
            int m=(l+r)/2;
            if(arr[m]<target){
                l=m+1;
            }
            else if(arr[m]>target){
               r=m-1;
            }
            else return true;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto arr:matrix){
        if(check(arr,target)) return true;
       }
       return false; 
    }
};
