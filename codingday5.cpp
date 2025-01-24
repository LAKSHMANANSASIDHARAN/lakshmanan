/*Indexes of Subarray Sum
This Problem stats they have given the array and target value and we need to find out the subarray which will give the target 
value if we add the subarray elements.
Tast is we need to find first subarray that gives the target value.
Algorithm:
We are going to use the two pointer  - sliding window and prefix sum algorithm.
*/

class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int Left=0,Right=0;
        int sum=0;
        vector<int>ret;
        while (Right < arr.size()) {
        sum += arr[Right];
        while (sum > target && Left <= Right) { /* if sum is greater that target we need to strink the window */
            sum -= arr[Left];
            Left++;
        }
        if (sum == target) {
            ret.push_back(Left+1);
            ret.push_back(Right+1);
            return ret;
        }
          Right++;
    }
      return {-1}; 
    }
};
/*Lets Take about the Time Complexity is O(n)and Space Complexity is O(1)  */

