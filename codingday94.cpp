/*Binary Search
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
You must write an algorithm with O(log n) runtime complexity.
Example 1:
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
Example 2:
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1,ans=-1;;
        while(left<=right){
            int mid=(right+left)/2;
            if(nums[mid]<target){
                left=mid+1;
            }
            else if(nums[mid]>target){
                right=mid-1;
            }
            else if(nums[mid]==target){
                ans=mid;
                break;
            }
        }
        return ans;;
    }
};
/* Guess Number Higher or Lower
We are playing the Guess Game. The game is as follows:
I pick a number from 1 to n. You have to guess which number I picked.
Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.
You call a pre-defined API int guess(int num), which returns three possible results:
-1: Your guess is higher than the number I picked (i.e. num > pick).
1: Your guess is lower than the number I picked (i.e. num < pick).
0: your guess is equal to the number I picked (i.e. num == pick).
Return the number that I picked.
Example 1:
Input: n = 10, pick = 6
Output: 6
Example 2:
Input: n = 1, pick = 1
Output: 1
Example 3:
Input: n = 2, pick = 1
Output: 1*/
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left=1,right=n,mid;
        while(left<=right){
             mid=left+(right-left)/2;
            if(guess(mid)==-1){
                right=mid-1;
            }
            else if(guess(mid)==1){
                left=mid+1;
            }
            else {
                break;
            }
        }
        return mid;
    }
};
/*Arranging Coins
You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.
Given the integer n, return the number of complete rows of the staircase you will build.
Example 1:
Input: n = 5
Output: 2
Explanation: Because the 3rd row is incomplete, we return 2.
Example 2:
Input: n = 8
Output: 3
Explanation: Because the 4th row is incomplete, we return 3.*/
class Solution {
public:
    int arrangeCoins(int n) {
        long long count=0;
        long long inc=1;
        for(long long i=1;i<=n;){
            inc++;
            count++;
            i+=inc;
            }
            return count;
    }
};
/* Minimum Common Value
Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.
Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.
Example 1:
Input: nums1 = [1,2,3], nums2 = [2,4]
Output: 2
Explanation: The smallest element common to both arrays is 2, so we return 2.
Example 2:
Input: nums1 = [1,2,3,6], nums2 = [2,3,4,5]
Output: 2
Explanation: There are two common elements in the array 2 and 3 out of which 2 is the smallest, so 2 is returned.
 */
class Solution {
    public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
      int i=0,j=0;
      while(i<nums1.size()&&j<nums2.size()){
        if(nums1[i]==nums2[j]){
             return nums1[i];
             break;
        }
        else if(nums1[i]<nums2[j]){
            i++;
        }
        else{
            j++;
        }
    }
    return -1;
      
    }
};
