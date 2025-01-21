
// https://leetcode.com/u/CzkAkW9SfL/ 

Week-1:
/*DAY-1!!!!!!!!
1.Maximum Points You Can Obtain from Cards -leetcode 1423[Sliding Window]
Problem Statement:
The problem is to find the maximum score you can achieve by choosing exactly k elements from either the beginning or the end of the array.
You need to maximize the sum of the selected elements.
SOLUTION:*/
class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n = arr.size();
        int maxi = INT_MIN;
        int sum = 0;
        for (int i = n - k; i < n; i++) {
            sum = sum + arr[i];
        }
        cout << "First max: " << sum << endl;
        maxi = max(maxi, sum);
        int i = n - k, j = 0;
        while (j < k) {
            sum = sum - arr[i];
            sum = sum + arr[j];
            cout << maxi << endl;
            maxi = max(maxi, sum);

            i++;
            j++;
        }
        return maxi;
    }
};
/*Explanation of the Code:
Initialization:

The size of the array is stored in n.
maxi is initialized to the smallest possible integer (INT_MIN) to track the maximum score.
sum is initialized to 0 to calculate the sum of elements in the selected window.
Calculate the Initial Window Sum:

The initial sum of the last k elements of the array is calculated, as the problem allows picking elements from the end.
Update the Maximum Score:

The calculated sum of the last k elements is stored in maxi since it is the first possible score.
Sliding Window Technique:

Use a two-pointer approach to slide the window from the end of the array to the beginning.
For each step:
Remove one element from the current window (from the end of the array).
Add one element from the start of the array to the window.
This ensures all possible combinations of k elements are considered, starting with the most elements from the end and progressively taking more from the start.
Update the Maximum:

After each adjustment to the window, compare the new sum to maxi and update maxi if the new sum is larger.
Return the Result:

The final value of maxi represents the maximum score possible.
Key Observations:
The sliding window ensures that all combinations of k elements are checked without recalculating the sum for overlapping elements repeatedly, which optimizes performance.
The algorithm efficiently finds the solution in O(k) time.

2.Score of a String -leetcode 3110[two pointer & string]
Problem Statement:
The problem asks you to calculate the score of a string, which is defined as the sum of
the absolute differences between the ASCII values of all adjacent characters in the string.*/
SOLUTION:
class Solution {
public:
    int scoreOfString(string s) {
        int output=0,i=0,j=1;
        while(j<s.size()){
            output+=abs(s[i]-s[j]);
            i++;j++;
        }
        return output;
    }
};
/* Explanation of the Code:

1. Initialization:
   `output` is initialized to `0` and will store the cumulative sum of absolute differences between adjacent characters.
    Two pointers, `i` and `j`, are initialized to `0` and `1` respectively. These will traverse the string to compare adjacent characters.

2. Iterate Through the String:
    A `while` loop is used to iterate through the string while `j` remains within the bounds of the string's size.
    For each iteration:
     Calculate the absolute difference between the ASCII values of characters at indices `i` and `j` (`s[i]` and `s[j]`).
      Add this difference to `output`.
     Increment both `i` and `j` to move to the next pair of adjacent characters.

3.Return the Result:
    Once the loop completes, `output` contains the sum of absolute differences between all adjacent characters in the string.
   The function returns `output` as the final result.

Key Observations:
The function efficiently computes the result in (O(n)) time, where (n) is the size of the string.
 The use of two pointers allows the algorithm to iterate through the string in a single pass, minimizing redundant computations.
 The function leverages the `abs` function to ensure all differences are treated as positive values, as required.*/

DAY-2!!!!
3. Longest Palindromic Substring-Leetcode 5[Two Pointer]:
Problem Statement:
Give the Longest Palindromic Substring!
Solution:
class Solution {
public:
string findpal(int i, int j, string& s) {
    while (i >= 0 && j < s.size() && s[i] == s[j]) {
        i--;
        j++;
    }
    return s.substr(i + 1, j - i - 1); 
}
 string longestPalindrome(string s) {
        int i=0;
  int n=s.size();
  int length=0;
  string ans="";
  for(i=0;i<n;i++){
    string sub1=findpal(i,i,s);
    if(sub1.length()>length){
      ans=sub1;
      length=ans.length();
    }
     string sub2=findpal(i,i+1,s);
    if(sub2.length()>length){
      ans=sub2;
      length=ans.length();
    }
}
    return ans;
    }
};
/*CODE EXPLANATION:
Approach
The solution uses a center expansion methoD:
1. Treat each character (and pair of adjacent characters) as the potential center of a palindrome.
2. Expand outward (to the left and right) while the characters match.
3. Track the longest palindrome found during the process.

 ode Walkthrough
1. `findpal` Function: Expands outward from a given center (or pair of centers) to find the longest palindrome substring centered at that position.
2. Main Function:
   Loop through each character in the string.
   Call `findpal` twice:
   Once considering the current character as the center.
   Once considering the current character and the next one as the center.
   Update the result if a longer palindrome is found.
3. Return the longest palindrome found.

Complexity
TimE: O(n^2), because each character expansion takes O(n), and we process each character.
Space: O(1), since we only use variables for tracking.*/

/*4.Jump Game II-Leetcode45[Greedy Algorithm!]
Problem Statement:
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:
0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].
Solution:*/
class Solution {
public:
    int jump(vector<int>& nums) {
      int i = 0, j = 0, farthest = 0, end = 0;
while (i < nums.size() - 1) {
    farthest = max(farthest, i + nums[i]);
    if (i == end) {
        J++;
        end = farthest;
    }
    i++;
}
return j;
};
/*CODE EXPLANATION:
1.Initialize Variables:
   i: Current index in the array.
   J: Count of jumps taken.
   farthest`: Farthest index that can be reached so far.
   end: The current range of the jump.

2. Iterate Through the Array:
   Update `farthest` to keep track of the maximum reach (`i + nums[i]`).
    If the current index `i` equals `end`, it means the range of the current jump is exhausted:
     Increment the jump count `J`.
     Update `end` to `farthest`, the new range.

3.Stop Condition:
   The loop runs until we reach the last element of the array (`i < nums.size() - 1`).

4. Return Result:
   Return the total number of jumps.

 Complexity:
Time Complexity: O(n), where n is the size of the array (each index is processed once).
Space Complexity:O(1), as no extra space is used.*/
