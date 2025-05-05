/* Largest Number
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
Since the result may be very large, so you need to return a string instead of an integer.
Example 1:
Input: nums = [10,2]
Output: "210"
Example 2:
Input: nums = [3,30,34,5,9]
Output: "9534330*/
bool compare(string& a, string& b) {
    return a + b > b + a;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> num;
        for (int i = 0; i < nums.size(); i++) {
            num.push_back(to_string(nums[i]));
        }
        sort(num.begin(), num.end(), compare);
        if (num[0] == "0") return "0";
        string res = "";
        for (auto it : num) {
            res += it;
        }
        return res;
    }
};
