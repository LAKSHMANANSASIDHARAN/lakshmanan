/*Clear Digits
You are given a string s.
Your task is to remove all digits by doing this operation repeatedly:
Delete the first digit and the closest non-digit character to its left.
Return the resulting string after removing all digits.
Example 1:
Input: s = "abc"
Output: "abc"
Explanation:
There is no digit in the string.
Example 2:
Input: s = "cb34"
Output: ""
Explanation:
First, we apply the operation on s[2], and s becomes "c4".
Then we apply the operation on s[1], and s becomes ""*/
class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        int i = 0;
        while (i < s.size()) {
            if (isalpha(s[i])) {
                st.push(s[i]);
            } else {
                st.pop();
            }
            i++;
        }
        string ans = "";
        while (!st.empty()) {
             ans = st.top() + ans;
            st.pop();
        }
         
        return ans;
       
    }
};
/*Majority Element II
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
Example 1:
Input: nums = [3,2,3]
Output: [3]
Example 2:
Input: nums = [1]
Output: [1]
Example 3:
Input: nums = [1,2]
Output: [1,2] */
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int n = nums.size();

        for (auto it : nums) {
            mpp[it]++;
        }
        vector<int> vec;
        for (auto& [f, l] : mpp) {
            if (l > n / 3) {
                vec.push_back(f);
            }
        }
        return vec;
    }
};
