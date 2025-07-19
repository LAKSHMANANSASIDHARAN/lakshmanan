/*744. Find Smallest Letter Greater Than Target
You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.
Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.
Example 1:

Input: letters = ["c","f","j"], target = "a"
Output: "c"
Explanation: The smallest character that is lexicographically greater than 'a' in letters is 'c'.
Example 2:

Input: letters = ["c","f","j"], target = "c"
Output: "f"
Explanation: The smallest character that is lexicographically greater than 'c' in letters is 'f'.
Example 3:

Input: letters = ["x","x","y","y"], target = "z"
Output: "x"
Explanation: There are no characters in letters that is lexicographically greater than 'z' so we return letters[0].*/
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans;
        if(letters[letters.size()-1]<=target) return letters[0];
        int left=0,right=letters.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(letters[mid]<=target){
                left=mid+1;
            }
            else if(letters[mid]>target){
                ans=letters[mid];
                right=mid-1;
            }
        }
        return ans;
    }
};
/*1346. Check If N and Its Double Exist
Given an array arr of integers, check if there exist two indices i and j such that :
i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]
 Example 1:

Input: arr = [10,2,5,3]
Output: true
Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]
Example 2:

Input: arr = [3,1,7,11]
Output: false
Explanation: There is no i and j that satisfy the conditions.*/
class Solution {
    bool check(int i, vector<int>& arr) {
    int target = 2 * arr[i];
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (mid == i) {
            if (arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        else if (arr[mid] < target) left = mid + 1;
        else if (arr[mid] > target) right = mid - 1;
        else return true;
    }
    return false;
}

public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(check(i,arr)) return true;
        }
        return false;
    }
};
